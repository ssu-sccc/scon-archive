#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> g[101010];
ll X[101010];
ll sum[101010];
int notsmall_idx[101010];
vector<int> not_small;
unordered_map<int,int> cnt[2048];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int sqm = (int)sqrt(m);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    not_small.push_back(0);
    for (int i = 1; i <= n; ++i) 
        if (g[i].size() > sqm) {
            notsmall_idx[i] = not_small.size();
            not_small.push_back(i);
        }
    for (int i = 1; i <= n; ++i) if (notsmall_idx[i]) {
        for (auto o : g[i]) cnt[notsmall_idx[i]][g[o].size()]++;
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, x; cin >> i >> x;
            X[i] += x;
            if (!notsmall_idx[i])
                for (auto o : g[i]) sum[g[o].size()] += x;
        } else {
            int d; cin >> d;
            ll ans = sum[d];
            for (auto o : not_small) {
                auto it = cnt[notsmall_idx[o]].find(d);
                if (it != cnt[notsmall_idx[o]].end())
                    ans += X[o] * it->second;
            }
            cout << ans << '\n';
        }
    }
}