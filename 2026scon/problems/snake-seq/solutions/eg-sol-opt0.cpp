#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u16 = uint16_t;
const int MAXN = 3005;
struct Point {
    ll x, y;
};
Point p[MAXN];
u16 bestLo[MAXN][MAXN], bestHi[MAXN][MAXN];
u16 loLen[MAXN], loPrev[MAXN], hiLen[MAXN], hiPrev[MAXN];
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
    auto cmpPrevPrev = [&](int a, int b, int v) -> int {
        ll lhs = (ll)(p[v].y - p[a].y) * (p[v].x - p[b].x);
        ll rhs = (ll)(p[v].y - p[b].y) * (p[v].x - p[a].x);
        if (lhs < rhs) return -1;
        if (lhs > rhs) return 1;
        return 0;
    };
    auto cmpPrevEdge = [&](int a, int v, int to) -> int {
        ll lhs = (ll)(p[v].y - p[a].y) * (p[to].x - p[v].x);
        ll rhs = (ll)(p[to].y - p[v].y) * (p[v].x - p[a].x);
        if (lhs < rhs) return -1;
        if (lhs > rhs) return 1;
        return 0;
    };
    auto updLo = [&](int v, int len, int prev) {
        u16& cell = bestLo[v][len];
        if (!cell || cmpPrevPrev(prev, cell - 1, v) < 0) cell = (u16)(prev + 1);
    };
    auto updHi = [&](int v, int len, int prev) {
        u16& cell = bestHi[v][len];
        if (!cell || cmpPrevPrev(prev, cell - 1, v) > 0) cell = (u16)(prev + 1);
    };
    for (int i = 1; i <= n; ++i) {
        bestLo[i][1] = 1;
        bestHi[i][1] = 1;
    }
    int ans = 1;
    vector<int> ord;
    ord.reserve(n);
    for (int j = 1; j <= n; ++j) {
        int loS = 0;
        for (int len = 1; len <= j; ++len) {
            u16 cell = bestLo[j][len];
            if (!cell) continue;
            u16 prev = cell - 1;
            while (loS && cmpPrevPrev(loPrev[loS - 1], prev, j) >= 0) --loS;
            loLen[loS] = (u16)len;
            loPrev[loS] = prev;
            ++loS;
        }
        int hiS = 0;
        for (int len = 1; len <= j; ++len) {
            u16 cell = bestHi[j][len];
            if (!cell) continue;
            u16 prev = cell - 1;
            while (hiS && cmpPrevPrev(hiPrev[hiS - 1], prev, j) <= 0) --hiS;
            hiLen[hiS] = (u16)len;
            hiPrev[hiS] = prev;
            ++hiS;
        }
        ord.clear();
        for (int k = j + 1; k <= n; ++k) {
            if (p[j].x < p[k].x && p[j].y < p[k].y) ord.push_back(k);
        }
        sort(ord.begin(), ord.end(), [&](int a, int b) {
return (p[a].y - p[j].y) * (p[b].x - p[j].x) < (p[b].y - p[j].y) * (p[a].x - p[j].x);
        });
        int ptr = 0;
        for (int k : ord) {
            while (ptr < loS && cmpPrevEdge(loPrev[ptr], j, k) < 0) ++ptr;
            if (ptr) {
                int cand = loLen[ptr - 1] + 1;
                updHi(k, cand, j);
                if (cand > ans) ans = cand;
            }
        }
        ptr = 0;
        for (int t = (int)ord.size() - 1; t >= 0; --t) {
            int k = ord[t];
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