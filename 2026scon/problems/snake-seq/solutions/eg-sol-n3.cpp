#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 3005;

struct Point {
    ll x, y;
};

Point p[MAXN];

uint16_t loLen[MAXN][MAXN], loPrev[MAXN][MAXN], loSz[MAXN];
uint16_t hiLen[MAXN][MAXN], hiPrev[MAXN][MAXN], hiSz[MAXN];

inline bool inc(int a, int b) {
    return p[a].x < p[b].x && p[a].y < p[b].y;
}

inline int cmpPrevPrev(int a, int b, int v) {
    ll lhs = (ll)(p[v].y - p[a].y) * (p[v].x - p[b].x);
    ll rhs = (ll)(p[v].y - p[b].y) * (p[v].x - p[a].x);
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

inline int cmpPrevEdge(int a, int v, int to) {
    ll lhs = (ll)(p[v].y - p[a].y) * (p[to].x - p[v].x);
    ll rhs = (ll)(p[to].y - p[v].y) * (p[v].x - p[a].x);
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
}

inline int queryLo(int v, int to) {
    for (int i = (int)loSz[v] - 1; i >= 0; --i) {
        if (cmpPrevEdge(loPrev[v][i], v, to) < 0) return loLen[v][i];
    }
    return 0;
}

inline int queryHi(int v, int to) {
    for (int i = (int)hiSz[v] - 1; i >= 0; --i) {
        if (cmpPrevEdge(hiPrev[v][i], v, to) > 0) return hiLen[v][i];
    }
    return 0;
}

inline void insertLo(int v, uint16_t L, uint16_t prev) {
    int s = loSz[v];
    int pos = 0;
    while (pos < s && loLen[v][pos] < L) ++pos;

    if (pos < s && loLen[v][pos] == L) {
        if (cmpPrevPrev(prev, loPrev[v][pos], v) >= 0) return;
        loPrev[v][pos] = prev;
    } else {
        for (int t = s; t > pos; --t) {
            loLen[v][t] = loLen[v][t - 1];
            loPrev[v][t] = loPrev[v][t - 1];
        }
        loLen[v][pos] = L;
        loPrev[v][pos] = prev;
        ++s;
    }

    if (pos + 1 < s && cmpPrevPrev(loPrev[v][pos + 1], loPrev[v][pos], v) <= 0) {
        for (int t = pos; t + 1 < s; ++t) {
            loLen[v][t] = loLen[v][t + 1];
            loPrev[v][t] = loPrev[v][t + 1];
        }
        loSz[v] = s - 1;
        return;
    }

    int left = pos - 1;
    while (left >= 0 && cmpPrevPrev(loPrev[v][left], loPrev[v][pos], v) >= 0) --left;

    int del = pos - (left + 1);
    if (del > 0) {
        for (int t = left + 1; t + del < s; ++t) {
            loLen[v][t] = loLen[v][t + del];
            loPrev[v][t] = loPrev[v][t + del];
        }
        s -= del;
    }

    loSz[v] = s;
}

inline void insertHi(int v, uint16_t L, uint16_t prev) {
    int s = hiSz[v];
    int pos = 0;
    while (pos < s && hiLen[v][pos] < L) ++pos;

    if (pos < s && hiLen[v][pos] == L) {
        if (cmpPrevPrev(prev, hiPrev[v][pos], v) <= 0) return;
        hiPrev[v][pos] = prev;
    } else {
        for (int t = s; t > pos; --t) {
            hiLen[v][t] = hiLen[v][t - 1];
            hiPrev[v][t] = hiPrev[v][t - 1];
        }
        hiLen[v][pos] = L;
        hiPrev[v][pos] = prev;
        ++s;
    }

    if (pos + 1 < s && cmpPrevPrev(hiPrev[v][pos + 1], hiPrev[v][pos], v) >= 0) {
        for (int t = pos; t + 1 < s; ++t) {
            hiLen[v][t] = hiLen[v][t + 1];
            hiPrev[v][t] = hiPrev[v][t + 1];
        }
        hiSz[v] = s - 1;
        return;
    }

    int left = pos - 1;
    while (left >= 0 && cmpPrevPrev(hiPrev[v][left], hiPrev[v][pos], v) <= 0) --left;

    int del = pos - (left + 1);
    if (del > 0) {
        for (int t = left + 1; t + del < s; ++t) {
            hiLen[v][t] = hiLen[v][t + del];
            hiPrev[v][t] = hiPrev[v][t + del];
        }
        s -= del;
    }

    hiSz[v] = s;
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
        loSz[i] = hiSz[i] = 1;
        loLen[i][0] = hiLen[i][0] = 1;
        loPrev[i][0] = hiPrev[i][0] = 0;
    }

    int ans = 1;

    for (int j = 1; j <= n; ++j) {
        for (int k = j + 1; k <= n; ++k) {
            if (!inc(j, k)) continue;

            int bestHi = queryLo(j, k);
            if (bestHi) {
                int cand = bestHi + 1;
                insertHi(k, (uint16_t)cand, (uint16_t)j);
                if (cand > ans) ans = cand;
            }

            int bestLo = queryHi(j, k);
            if (bestLo) {
                int cand = bestLo + 1;
                insertLo(k, (uint16_t)cand, (uint16_t)j);
                if (cand > ans) ans = cand;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}