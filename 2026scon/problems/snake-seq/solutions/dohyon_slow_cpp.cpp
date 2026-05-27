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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Pair> L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i].x >> L[i].y;

    sort(L.begin(), L.end(), [](const Pair& a, const Pair& b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    int ans = 1;
    vector<bool> visit(N, false);

    vector<vector<vector<pair<Pair, int>>>> T(2, vector<vector<pair<Pair, int>>>(N));

    auto cmp = [](const pair<Pair, int>& a, const pair<Pair, int>& b) {
        return a.first < b.first;
    };

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < j; i++) {
            if (L[i].x < L[j].x && L[i].y < L[j].y) {

                if (!visit[i]) {
                    visit[i] = true;

                    T[0][i].push_back({L[i], 1});
                    T[1][i].push_back({L[i], 1});

                    auto& t0 = T[0][i];
                    sort(t0.begin(), t0.end(), cmp);
                    vector<pair<Pair, int>> clean0;
                    for (auto& p : t0) {
                        if (clean0.empty() || clean0.back().first < p.first) {
                            clean0.push_back(p);
                        } else {
                            clean0.back().second = max(clean0.back().second, p.second);
                        }
                    }
                    int mx = 0;
                    for (auto& p : clean0) {
                        mx = max(mx, p.second);
                        p.second = mx;
                    }
                    T[0][i] = clean0;
                    T[0][i].shrink_to_fit();

                    auto& t1 = T[1][i];
                    sort(t1.begin(), t1.end(), cmp);
                    vector<pair<Pair, int>> clean1;
                    for (auto& p : t1) {
                        if (clean1.empty() || clean1.back().first < p.first) {
                            clean1.push_back(p);
                        } else {
                            clean1.back().second = max(clean1.back().second, p.second);
                        }
                    }
                    mx = 0;
                    for (int k = (int)clean1.size() - 1; k >= 0; --k) {
                        mx = max(mx, clean1[k].second);
                        clean1[k].second = mx;
                    }
                    T[1][i] = clean1;
                    T[1][i].shrink_to_fit();
                }

                ll dx = L[j].x - L[i].x;
                ll dy = L[j].y - L[i].y;
                Pair tmp(dx, dy);

                auto it_lo = lower_bound(T[0][i].begin(), T[0][i].end(), make_pair(tmp, 0), cmp);
                if (it_lo != T[0][i].begin()) {
                    --it_lo;
                    int val = it_lo->second + 1;
                    T[1][j].push_back({tmp, val});
                    ans = max(ans, val);
                }

                auto it_hi = upper_bound(T[1][i].begin(), T[1][i].end(), make_pair(tmp, 0), cmp);
                if (it_hi != T[1][i].end()) {
                    int val = it_hi->second + 1;
                    T[0][j].push_back({tmp, val});
                    ans = max(ans, val);
                }
            }
        }
    }

    cout << ans;
}