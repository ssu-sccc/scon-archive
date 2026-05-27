#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 3000;
static constexpr unsigned short INVALID = 0xFFFFu;

struct Point {
    int x, y;
};

struct State {
    int dx, dy;
    unsigned short d0, d1;
};

alignas(64) static Point p[MAXN + 1];
alignas(64) static unsigned short pos[(MAXN + 1) * (MAXN + 1)];
alignas(64) static int rowStart[MAXN + 2], rowLen[MAXN + 2];
alignas(64) static State st[(MAXN + 1) * (MAXN + 2) / 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
                st[ptr] = {xj - p[i].x, yj - p[i].y, 0, 0};
                ++ptr;
            }
        }

        rowLen[j] = ptr - rowStart[j];
        st[rowStart[j]].d0 = 1;
        st[rowStart[j]].d1 = 1;
    }

    int ans = min(n, 1);

    for (int j = 1; j <= n; ++j) {
        const int sj = rowStart[j];
        const int ej = sj + rowLen[j];
        const int xj = p[j].x;
        const int yj = p[j].y;

        for (int k = j + 1; k <= n; ++k) {
            const unsigned short off = pos[k * STR + j];
            if (off == INVALID) continue;

            const unsigned long long dx2 = (unsigned int)(p[k].x - xj);
            const unsigned long long dy2 = (unsigned int)(p[k].y - yj);

            unsigned short best0 = 0, best1 = 0;
            int t = sj;

            for (; t + 3 < ej; t += 4) {
                unsigned long long l0 = (unsigned long long)(unsigned int)st[t].dy * dx2;
                unsigned long long r0 = dy2 * (unsigned long long)(unsigned int)st[t].dx;
                if (l0 < r0) {
                    unsigned short v = (unsigned short)(st[t].d1 + 1);
                    if (v > best0) best0 = v;
                } else if (l0 > r0) {
                    unsigned short v = (unsigned short)(st[t].d0 + 1);
                    if (v > best1) best1 = v;
                }

                unsigned long long l1 = (unsigned long long)(unsigned int)st[t + 1].dy * dx2;
                unsigned long long r1 = dy2 * (unsigned long long)(unsigned int)st[t + 1].dx;
                if (l1 < r1) {
                    unsigned short v = (unsigned short)(st[t + 1].d1 + 1);
                    if (v > best0) best0 = v;
                } else if (l1 > r1) {
                    unsigned short v = (unsigned short)(st[t + 1].d0 + 1);
                    if (v > best1) best1 = v;
                }

                unsigned long long l2 = (unsigned long long)(unsigned int)st[t + 2].dy * dx2;
                unsigned long long r2 = dy2 * (unsigned long long)(unsigned int)st[t + 2].dx;
                if (l2 < r2) {
                    unsigned short v = (unsigned short)(st[t + 2].d1 + 1);
                    if (v > best0) best0 = v;
                } else if (l2 > r2) {
                    unsigned short v = (unsigned short)(st[t + 2].d0 + 1);
                    if (v > best1) best1 = v;
                }

                unsigned long long l3 = (unsigned long long)(unsigned int)st[t + 3].dy * dx2;
                unsigned long long r3 = dy2 * (unsigned long long)(unsigned int)st[t + 3].dx;
                if (l3 < r3) {
                    unsigned short v = (unsigned short)(st[t + 3].d1 + 1);
                    if (v > best0) best0 = v;
                } else if (l3 > r3) {
                    unsigned short v = (unsigned short)(st[t + 3].d0 + 1);
                    if (v > best1) best1 = v;
                }
            }

            for (; t < ej; ++t) {
                unsigned long long lhs = (unsigned long long)(unsigned int)st[t].dy * dx2;
                unsigned long long rhs = dy2 * (unsigned long long)(unsigned int)st[t].dx;

                if (lhs < rhs) {
                    unsigned short v = (unsigned short)(st[t].d1 + 1);
                    if (v > best0) best0 = v;
                } else if (lhs > rhs) {
                    unsigned short v = (unsigned short)(st[t].d0 + 1);
                    if (v > best1) best1 = v;
                }
            }

            State &dst = st[rowStart[k] + off];
            dst.d0 = best0;
            dst.d1 = best1;

            if (best0 > ans) ans = best0;
            if (best1 > ans) ans = best1;
        }
    }

    cout << ans << '\n';
    return 0;
}