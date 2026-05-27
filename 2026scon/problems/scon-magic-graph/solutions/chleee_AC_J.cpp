#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    int N, M, Q; cin >> N >> M >> Q;

    vector<ll> deg(N+1, 0);
    vector<ll> adj[N+1];
    for (int i = 0; i < M; i++ ){
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    map<ll, ll> m[N+1];
    for (ll i = 1; i <= N; i++) {
        for (auto &x : adj[i]) {
            m[i][deg[x]]++;
        }
    }

    vector<ll> ans(N+1, 0);
    while (Q--) {
        int q; cin >> q;
        if (q == 1) {
            ll u, x; cin >> u >> x;
            for (auto &e : m[u]) {
                ans[e.x] += e.y * x;
            }
        } else {
            int d; cin >> d; cout << ans[d] << endl;
        }
    }
    return 0;
}