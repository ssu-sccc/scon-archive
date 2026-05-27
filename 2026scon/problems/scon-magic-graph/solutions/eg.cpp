#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll, ll> pi;
ll ans[101010];
vector<int> V[101010];
vector<pi> g[101010];
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
    vector<int> v;
    for (int w : V[i])
      v.push_back(V[w].size());
    sort(all(v));

    for (int j = 0; j < v.size();) {
      int k = j + 1;
      while (k < v.size() && v[j] == v[k])
        k++;
      g[i].push_back(pi(v[j], k - j));
      j = k;
    }
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
