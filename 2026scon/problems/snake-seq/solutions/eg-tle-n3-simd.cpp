#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

static constexpr int MAXN = 3000;
static constexpr unsigned short INVALID = 0xFFFFu;

struct Point {
    int x, y;
};

alignas(64) static Point p[MAXN + 1];
alignas(64) static int rowStart[MAXN + 2], rowLen[MAXN + 2];
alignas(64) static unsigned short pos[(MAXN + 1) * (MAXN + 1)];
alignas(64) static int dxv[(MAXN + 1) * (MAXN + 2) / 2];
alignas(64) static int dyv[(MAXN + 1) * (MAXN + 2) / 2];
alignas(64) static int dp0[(MAXN + 1) * (MAXN + 2) / 2];
alignas(64) static int dp1[(MAXN + 1) * (MAXN + 2) / 2];
alignas(64) static __m256i maskTable[256];
static unsigned char spread4[16];

static inline int reduce_max8(__m256i v) {
    alignas(32) int tmp[8];
    _mm256_store_si256((__m256i*)tmp, v);
    int r = tmp[0];
    for (int i = 1; i < 8; ++i) r = max(r, tmp[i]);
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    spread4[0] = 0;
    for (int m = 1; m < 16; ++m) {
        unsigned char s = 0;
        if (m & 1) s |= 1u << 0;
        if (m & 2) s |= 1u << 2;
        if (m & 4) s |= 1u << 4;
        if (m & 8) s |= 1u << 6;
        spread4[m] = s;
    }
    for (int m = 0; m < 256; ++m) {
        alignas(32) int a[8];
        for (int i = 0; i < 8; ++i) a[i] = (m >> i) & 1 ? -1 : 0;
        maskTable[m] = _mm256_load_si256((__m256i*)a);
    }

    int n;
    cin >> n;
    p[0] = {0, 0};
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;

    sort(p + 1, p + n + 1, [](const Point& a, const Point& b) {
        return a.x != b.x ? a.x < b.x : a.y < b.y;
    });

    const int STR = n + 1;
    fill(pos, pos + STR * STR, INVALID);

    int ptr = 0;
    for (int j = 1; j <= n; ++j) {
        rowStart[j] = ptr;
        const int xj = p[j].x;
        const int yj = p[j].y;
        for (int i = 0; i < j; ++i) {
            if (p[i].x < xj && p[i].y < yj) {
                pos[j * STR + i] = (unsigned short)(ptr - rowStart[j]);
                dxv[ptr] = xj - p[i].x;
                dyv[ptr] = yj - p[i].y;
                dp0[ptr] = 0;
                dp1[ptr] = 0;
                ++ptr;
            }
        }
        rowLen[j] = ptr - rowStart[j];
        if (rowLen[j] > 0) {
            dp0[rowStart[j]] = 1;
            dp1[rowStart[j]] = 1;
        }
    }

    int ans = min(n, 1);
    const __m256i vone = _mm256_set1_epi32(1);

    for (int j = 1; j <= n; ++j) {
        const int sj = rowStart[j];
        const int len = rowLen[j];
        const int ej = sj + len;
        const int xj = p[j].x;
        const int yj = p[j].y;

        for (int k = j + 1; k <= n; ++k) {
            const unsigned short off = pos[k * STR + j];
            if (off == INVALID) continue;

            const int dx2 = p[k].x - xj;
            const int dy2 = p[k].y - yj;
            const __m256i vdx2 = _mm256_set1_epi32(dx2);
            const __m256i vdy2 = _mm256_set1_epi32(dy2);

            __m256i best0v = _mm256_setzero_si256();
            __m256i best1v = _mm256_setzero_si256();

            int t = sj;
            for (; t + 8 <= ej; t += 8) {
                __m256i vdx1 = _mm256_loadu_si256((const __m256i*)(dxv + t));
                __m256i vdy1 = _mm256_loadu_si256((const __m256i*)(dyv + t));

                __m256i lhsE = _mm256_mul_epu32(vdy1, vdx2);
                __m256i rhsE = _mm256_mul_epu32(vdx1, vdy2);
                __m256i vdx1o = _mm256_srli_epi64(vdx1, 32);
                __m256i vdy1o = _mm256_srli_epi64(vdy1, 32);
                __m256i lhsO = _mm256_mul_epu32(vdy1o, vdx2);
                __m256i rhsO = _mm256_mul_epu32(vdx1o, vdy2);

                int gtE = _mm256_movemask_pd(_mm256_castsi256_pd(_mm256_cmpgt_epi64(lhsE, rhsE)));
                int gtO = _mm256_movemask_pd(_mm256_castsi256_pd(_mm256_cmpgt_epi64(lhsO, rhsO)));
                int ltE = _mm256_movemask_pd(_mm256_castsi256_pd(_mm256_cmpgt_epi64(rhsE, lhsE)));
                int ltO = _mm256_movemask_pd(_mm256_castsi256_pd(_mm256_cmpgt_epi64(rhsO, lhsO)));

                const unsigned char maskLt = (unsigned char)(spread4[ltE] | (spread4[ltO] << 1));
                const unsigned char maskGt = (unsigned char)(spread4[gtE] | (spread4[gtO] << 1));

                __m256i cand0 = _mm256_add_epi32(_mm256_loadu_si256((const __m256i*)(dp1 + t)), vone);
                __m256i cand1 = _mm256_add_epi32(_mm256_loadu_si256((const __m256i*)(dp0 + t)), vone);
                cand0 = _mm256_and_si256(cand0, maskTable[maskLt]);
                cand1 = _mm256_and_si256(cand1, maskTable[maskGt]);
                best0v = _mm256_max_epi32(best0v, cand0);
                best1v = _mm256_max_epi32(best1v, cand1);
            }

            int best0 = reduce_max8(best0v);
            int best1 = reduce_max8(best1v);

            for (; t < ej; ++t) {
                unsigned long long lhs = 1ull * (unsigned int)dyv[t] * (unsigned int)dx2;
                unsigned long long rhs = 1ull * (unsigned int)dxv[t] * (unsigned int)dy2;
                if (lhs < rhs) best0 = max(best0, dp1[t] + 1);
                else if (lhs > rhs) best1 = max(best1, dp0[t] + 1);
            }

            const int idx = rowStart[k] + off;
            dp0[idx] = best0;
            dp1[idx] = best1;
            ans = max(ans, max(best0, best1));
        }
    }

    cout << ans << '\n';
    return 0;
}