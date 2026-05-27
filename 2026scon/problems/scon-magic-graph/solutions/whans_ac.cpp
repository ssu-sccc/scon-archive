#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector G(n+1, vector<int>());
    vector A(n+1, vector<P>());
    vector<int> D(n+1);
    for (int s = 0; s < m; s++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        D[u]++; D[v]++;
    }
    for (int s = 1; s <= n; s++) sort(all(G[s]), [&] (int a,int b){ 
        return D[a] < D[b];
    });
    for (int s = 1; s <= n; s++) {
        int sz = G[s].size();
        for (int i = 0, j = 0; i < sz; i = j) {
            while (j < sz && D[G[s][i]] == D[G[s][j]]) j++;
            A[s].push_back({D[G[s][i]], j-i});
        }
    }
    vector<ll> S(n+1);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            ll i, x; cin >> i >> x;
            for (auto [d, sz] : A[i]) S[d] += sz * x;
        } else {
            ll x; cin >> x;
            cout << S[x] << "\n";
        }
    }
    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}