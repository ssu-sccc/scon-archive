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
alignas(32) static int maskWords256[256][8];
static unsigned char spread4[16];
static unsigned short spread8[256];

static inline void build_tables() {
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
        unsigned short s = 0;
        for (int i = 0; i < 8; ++i) {
            if (m & (1 << i)) s |= (unsigned short)(1u << (2 * i));
            maskWords256[m][i] = (m >> i) & 1 ? -1 : 0;
        }
        spread8[m] = s;
    }
}

static inline void build_states(int n) {
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
        dp0[rowStart[j]] = 1;
        dp1[rowStart[j]] = 1;
    }
}

__attribute__((target("avx512f,avx512vl,avx512dq")))
static int solve_avx512(int n) {
    int ans = min(n, 1);
    const int STR = n + 1;
    const __m512i vone = _mm512_set1_epi32(1);

    for (int j = 1; j <= n; ++j) {
        const int sj = rowStart[j];
        const int ej = sj + rowLen[j];
        const int xj = p[j].x;
        const int yj = p[j].y;

        for (int k = j + 1; k <= n; ++k) {
            const unsigned short off = pos[k * STR + j];
            if (off == INVALID) continue;

            const int dx2 = p[k].x - xj;
            const int dy2 = p[k].y - yj;
            const __m512i vdx2 = _mm512_set1_epi32(dx2);
            const __m512i vdy2 = _mm512_set1_epi32(dy2);

            __m512i best0v = _mm512_setzero_si512();
            __m512i best1v = _mm512_setzero_si512();

            int t = sj;
            for (; t + 16 <= ej; t += 16) {
                __m512i vdx1 = _mm512_loadu_si512((const void*)(dxv + t));
                __m512i vdy1 = _mm512_loadu_si512((const void*)(dyv + t));

                __m512i lhsE = _mm512_mul_epu32(vdy1, vdx2);
                __m512i rhsE = _mm512_mul_epu32(vdx1, vdy2);
                __m512i vdx1o = _mm512_srli_epi64(vdx1, 32);
                __m512i vdy1o = _mm512_srli_epi64(vdy1, 32);
                __m512i lhsO = _mm512_mul_epu32(vdy1o, vdx2);
                __m512i rhsO = _mm512_mul_epu32(vdx1o, vdy2);

                const unsigned gtE = (unsigned)_mm512_cmpgt_epi64_mask(lhsE, rhsE);
                const unsigned gtO = (unsigned)_mm512_cmpgt_epi64_mask(lhsO, rhsO);
                const unsigned ltE = (unsigned)_mm512_cmpgt_epi64_mask(rhsE, lhsE);
                const unsigned ltO = (unsigned)_mm512_cmpgt_epi64_mask(rhsO, lhsO);

                const __mmask16 maskLt = (__mmask16)(spread8[ltE] | (unsigned)(spread8[ltO] << 1));
                const __mmask16 maskGt = (__mmask16)(spread8[gtE] | (unsigned)(spread8[gtO] << 1));

                __m512i cand0 = _mm512_add_epi32(_mm512_loadu_si512((const void*)(dp1 + t)), vone);
                __m512i cand1 = _mm512_add_epi32(_mm512_loadu_si512((const void*)(dp0 + t)), vone);
                best0v = _mm512_max_epi32(best0v, _mm512_maskz_mov_epi32(maskLt, cand0));
                best1v = _mm512_max_epi32(best1v, _mm512_maskz_mov_epi32(maskGt, cand1));
            }

            alignas(64) int buf0[16], buf1[16];
            _mm512_store_si512((void*)buf0, best0v);
            _mm512_store_si512((void*)buf1, best1v);
            int best0 = 0, best1 = 0;
            for (int u = 0; u < 16; ++u) {
                if (buf0[u] > best0) best0 = buf0[u];
                if (buf1[u] > best1) best1 = buf1[u];
            }

            for (; t + 3 < ej; t += 4) {
                unsigned long long lhs0 = 1ull * (unsigned int)dyv[t] * (unsigned int)dx2;
                unsigned long long rhs0 = 1ull * (unsigned int)dxv[t] * (unsigned int)dy2;
                if (lhs0 < rhs0) best0 = max(best0, dp1[t] + 1);
                else if (lhs0 > rhs0) best1 = max(best1, dp0[t] + 1);

                unsigned long long lhs1 = 1ull * (unsigned int)dyv[t + 1] * (unsigned int)dx2;
                unsigned long long rhs1 = 1ull * (unsigned int)dxv[t + 1] * (unsigned int)dy2;
                if (lhs1 < rhs1) best0 = max(best0, dp1[t + 1] + 1);
                else if (lhs1 > rhs1) best1 = max(best1, dp0[t + 1] + 1);

                unsigned long long lhs2 = 1ull * (unsigned int)dyv[t + 2] * (unsigned int)dx2;
                unsigned long long rhs2 = 1ull * (unsigned int)dxv[t + 2] * (unsigned int)dy2;
                if (lhs2 < rhs2) best0 = max(best0, dp1[t + 2] + 1);
                else if (lhs2 > rhs2) best1 = max(best1, dp0[t + 2] + 1);

                unsigned long long lhs3 = 1ull * (unsigned int)dyv[t + 3] * (unsigned int)dx2;
                unsigned long long rhs3 = 1ull * (unsigned int)dxv[t + 3] * (unsigned int)dy2;
                if (lhs3 < rhs3) best0 = max(best0, dp1[t + 3] + 1);
                else if (lhs3 > rhs3) best1 = max(best1, dp0[t + 3] + 1);
            }
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
    return ans;
}

__attribute__((target("avx2")))
static int solve_avx2(int n) {
    int ans = min(n, 1);
    const int STR = n + 1;
    const __m256i vone = _mm256_set1_epi32(1);

    for (int j = 1; j <= n; ++j) {
        const int sj = rowStart[j];
        const int ej = sj + rowLen[j];
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
                cand0 = _mm256_and_si256(cand0, _mm256_load_si256((const __m256i*)maskWords256[maskLt]));
                cand1 = _mm256_and_si256(cand1, _mm256_load_si256((const __m256i*)maskWords256[maskGt]));
                best0v = _mm256_max_epi32(best0v, cand0);
                best1v = _mm256_max_epi32(best1v, cand1);
            }

            alignas(32) int buf0[8], buf1[8];
            _mm256_store_si256((__m256i*)buf0, best0v);
            _mm256_store_si256((__m256i*)buf1, best1v);
            int best0 = 0, best1 = 0;
            for (int u = 0; u < 8; ++u) {
                if (buf0[u] > best0) best0 = buf0[u];
                if (buf1[u] > best1) best1 = buf1[u];
            }

            for (; t + 3 < ej; t += 4) {
                unsigned long long lhs0 = 1ull * (unsigned int)dyv[t] * (unsigned int)dx2;
                unsigned long long rhs0 = 1ull * (unsigned int)dxv[t] * (unsigned int)dy2;
                if (lhs0 < rhs0) best0 = max(best0, dp1[t] + 1);
                else if (lhs0 > rhs0) best1 = max(best1, dp0[t] + 1);

                unsigned long long lhs1 = 1ull * (unsigned int)dyv[t + 1] * (unsigned int)dx2;
                unsigned long long rhs1 = 1ull * (unsigned int)dxv[t + 1] * (unsigned int)dy2;
                if (lhs1 < rhs1) best0 = max(best0, dp1[t + 1] + 1);
                else if (lhs1 > rhs1) best1 = max(best1, dp0[t + 1] + 1);

                unsigned long long lhs2 = 1ull * (unsigned int)dyv[t + 2] * (unsigned int)dx2;
                unsigned long long rhs2 = 1ull * (unsigned int)dxv[t + 2] * (unsigned int)dy2;
                if (lhs2 < rhs2) best0 = max(best0, dp1[t + 2] + 1);
                else if (lhs2 > rhs2) best1 = max(best1, dp0[t + 2] + 1);

                unsigned long long lhs3 = 1ull * (unsigned int)dyv[t + 3] * (unsigned int)dx2;
                unsigned long long rhs3 = 1ull * (unsigned int)dxv[t + 3] * (unsigned int)dy2;
                if (lhs3 < rhs3) best0 = max(best0, dp1[t + 3] + 1);
                else if (lhs3 > rhs3) best1 = max(best1, dp0[t + 3] + 1);
            }
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
    return ans;
}

static int solve_scalar(int n) {
    int ans = min(n, 1);
    const int STR = n + 1;
    for (int j = 1; j <= n; ++j) {
        const int sj = rowStart[j];
        const int ej = sj + rowLen[j];
        const int xj = p[j].x;
        const int yj = p[j].y;
        for (int k = j + 1; k <= n; ++k) {
            const unsigned short off = pos[k * STR + j];
            if (off == INVALID) continue;
            const int dx2 = p[k].x - xj;
            const int dy2 = p[k].y - yj;
            int best0 = 0, best1 = 0;
            for (int t = sj; t < ej; ++t) {
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
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_tables();

    int n;
    cin >> n;
    p[0] = {0, 0};
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;

    build_states(n);

    __builtin_cpu_init();
    int ans;
    if (__builtin_cpu_supports("avx512f") && __builtin_cpu_supports("avx512vl") && __builtin_cpu_supports("avx512dq")) ans = solve_avx512(n);
    else if (__builtin_cpu_supports("avx2")) ans = solve_avx2(n);
    else ans = solve_scalar(n);

    cout << ans << '\n';
    return 0;
}