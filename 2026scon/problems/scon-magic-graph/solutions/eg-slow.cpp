#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
ll ans[101010];
vector<int> V[101010];
map<ll, ll> g[101010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    for (int w : V[i])
      g[i][V[w].size()]++;
  }
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll u, x;
      cin >> u >> x;
      for (auto &p : g[u])
        ans[p.first] += p.second * x;
    } else {
      ll d;
      cin >> d;
      cout << ans[d] << '\n';
    }
  }
  return 0;
}
