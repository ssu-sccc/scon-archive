#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u16 = uint16_t;

const int MAXN = 3005;
const int TH = 20;

struct Point {
    ll x, y;
};

Point p[MAXN];
u16 bestLo[MAXN][MAXN], bestHi[MAXN][MAXN];
u16 loLen[MAXN], loPrev[MAXN], hiLen[MAXN], hiPrev[MAXN];
int ord[MAXN];

inline int cmpPrevPrev(int a, int b, int v) {
    ll lhs = (p[v].y - p[a].y) * (p[v].x - p[b].x);
    ll rhs = (p[v].y - p[b].y) * (p[v].x - p[a].x);
    return (lhs > rhs) - (lhs < rhs);
}

inline int cmpPrevEdge(int a, int v, int to) {
    ll lhs = (p[v].y - p[a].y) * (p[to].x - p[v].x);
    ll rhs = (p[to].y - p[v].y) * (p[v].x - p[a].x);
    return (lhs > rhs) - (lhs < rhs);
}

inline void updLo(int v, int len, int prev) {
    u16 &cell = bestLo[v][len];
    if (!cell || cmpPrevPrev(prev, cell - 1, v) < 0) cell = (u16)(prev + 1);
}

inline void updHi(int v, int len, int prev) {
    u16 &cell = bestHi[v][len];
    if (!cell || cmpPrevPrev(prev, cell - 1, v) > 0) cell = (u16)(prev + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    p[0] = {0, 0};
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;

    sort(p + 1, p + n + 1, [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    for (int i = 1; i <= n; ++i) {
        bestLo[i][1] = 1;
        bestHi[i][1] = 1;
    }

    int ans = 1;

    for (int j = 1; j <= n; ++j) {
        int loS = 0;
        for (int len = 1; len <= j; ++len) {
            u16 cell = bestLo[j][len];
            if (!cell) continue;
            int prev = cell - 1;
            while (loS && cmpPrevPrev(loPrev[loS - 1], prev, j) >= 0) --loS;
            loLen[loS] = (u16)len;
            loPrev[loS] = (u16)prev;
            ++loS;
        }

        int hiS = 0;
        for (int len = 1; len <= j; ++len) {
            u16 cell = bestHi[j][len];
            if (!cell) continue;
            int prev = cell - 1;
            while (hiS && cmpPrevPrev(hiPrev[hiS - 1], prev, j) <= 0) --hiS;
            hiLen[hiS] = (u16)len;
            hiPrev[hiS] = (u16)prev;
            ++hiS;
        }

        if (loS + hiS <= TH) {
            for (int k = j + 1; k <= n; ++k) {
                if (!(p[j].x < p[k].x && p[j].y < p[k].y)) continue;

                for (int t = loS - 1; t >= 0; --t) {
                    if (cmpPrevEdge(loPrev[t], j, k) < 0) {
                        int cand = loLen[t] + 1;
                        updHi(k, cand, j);
                        if (cand > ans) ans = cand;
                        break;
                    }
                }

                for (int t = hiS - 1; t >= 0; --t) {
                    if (cmpPrevEdge(hiPrev[t], j, k) > 0) {
                        int cand = hiLen[t] + 1;
                        updLo(k, cand, j);
                        if (cand > ans) ans = cand;
                        break;
                    }
                }
            }
            continue;
        }

        int m = 0;
        for (int k = j + 1; k <= n; ++k) {
            if (p[j].x < p[k].x && p[j].y < p[k].y) ord[m++] = k;
        }

        sort(ord, ord + m, [&](int a, int b) {
            return (p[a].y - p[j].y) * (p[b].x - p[j].x) < (p[b].y - p[j].y) * (p[a].x - p[j].x);
        });

        int ptr = 0;
        for (int i = 0; i < m; ++i) {
            int k = ord[i];
            while (ptr < loS && cmpPrevEdge(loPrev[ptr], j, k) < 0) ++ptr;
            if (ptr) {
                int cand = loLen[ptr - 1] + 1;
                updHi(k, cand, j);
                if (cand > ans) ans = cand;
            }
        }

        ptr = 0;
        for (int i = m - 1; i >= 0; --i) {
            int k = ord[i];
            while (ptr < hiS && cmpPrevEdge(hiPrev[ptr], j, k) > 0) ++ptr;
            if (ptr) {
                int cand = hiLen[ptr - 1] + 1;
                updLo(k, cand, j);
                if (cand > ans) ans = cand;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}