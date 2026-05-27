#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")
using namespace std;

typedef long long ll;

struct Pair {
    ll x, y;
    Pair() {}
    Pair(ll x, ll y) : x(x), y(y) {}

    bool operator<(const Pair& o) const {
        return y * o.x < o.y * x;
    }
};

struct Tuple {
    Pair p;
    int i, j;
    Tuple() {}
    Tuple(Pair p, int i, int j) : p(p), i(i), j(j) {}
};

int lowerKey(Pair tmp, vector<Tuple>& L) {
    int s = -1, e = (int)L.size(), m;
    while (s + 1 < e) {
        m = (s + e) >> 1;
        if (L[m].p < tmp)
            s = m;
        else
            e = m;
    }
    return s;
}

int higherKey(Pair tmp, vector<Tuple>& L) {
    int s = -1, e = (int)L.size(), m;
    while (s + 1 < e) {
        m = (s + e) >> 1;
        if (tmp < L[m].p)
            e = m;
        else
            s = m;
    }
    return e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Pair> L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i].x >> L[i].y;

    sort(L.begin(), L.end(), [](const Pair& o1, const Pair& o2) {
        if (o1.x == o2.x) return o1.y < o2.y;
        return o1.x < o2.x;
    });

    vector<Tuple> T;
    for (int i = 0; i < N; i++) {
        T.emplace_back(L[i], -1, i);
        for (int j = 0; j < N; j++)
            if (L[i].x < L[j].x && L[i].y < L[j].y)
                T.emplace_back(Pair(L[j].x - L[i].x, L[j].y - L[i].y), i, j);
    }

    sort(T.begin(), T.end(), [](const Tuple& o1, const Tuple& o2) {
        return o1.p < o2.p;
    });

    int ans = 1;
    vector<bool> visit(N, false);
    vector<vector<Tuple>> sortv(N);

    for (auto& t : T) {
        int j = t.j;
        t.i = t.j = (t.i == -1 ? 1 : 0);

        if (!sortv[j].empty() && !(t.p < sortv[j].back().p) && !(sortv[j].back().p < t.p)) {
            if (t.i == 1)
                sortv[j].back().i = sortv[j].back().j = 1;
        } else {
            sortv[j].push_back(t);
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < j; i++) {
            if (L[i].x < L[j].x && L[i].y < L[j].y) {

                if (!visit[i]) {
                    visit[i] = true;

                    for (int k = 1; k < (int)sortv[i].size(); k++)
                        sortv[i][k].i = max(sortv[i][k].i, sortv[i][k - 1].i);

                    for (int k = (int)sortv[i].size() - 2; k >= 0; k--)
                        sortv[i][k].j = max(sortv[i][k].j, sortv[i][k + 1].j);
                }

                ll dx = L[j].x - L[i].x;
                ll dy = L[j].y - L[i].y;
                Pair tmp(dx, dy);

                int lo = lowerKey(tmp, sortv[i]);
                int hi = higherKey(tmp, sortv[i]);
                int idx = lowerKey(tmp, sortv[j]) + 1;

                if (lo != -1 && sortv[i][lo].i != 0) {
                    int val = sortv[i][lo].i + 1;
                    sortv[j][idx].j = max(sortv[j][idx].j, val);
                    ans = max(ans, val);
                }

                if (hi != (int)sortv[i].size() && sortv[i][hi].j != 0) {
                    int val = sortv[i][hi].j + 1;
                    sortv[j][idx].i = max(sortv[j][idx].i, val);
                    ans = max(ans, val);
                }
            }
        }
    }

    cout << ans;
}