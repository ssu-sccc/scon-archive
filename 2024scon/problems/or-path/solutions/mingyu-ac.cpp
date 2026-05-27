#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;
vector<tuple<int64_t, int, int>> edge;
vector<int> par;
int find(int node) {
  return par[node] == node ? node : par[node] = find(par[node]);
}
void join(int u, int v) { par[find(u)] = find(v); }
void reset() { iota(par.begin(), par.end(), 0); }

void solve() {
  cin >> n >> m;
  par.assign(n, 0);
  reset();

  for (int i = 0; i < m; ++i) {
    int64_t u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, u - 1, v - 1});
  }
  int64_t req_zero = 0;
  int64_t ans = 0;
  for (int bit = 59; bit >= 0; --bit) {
    // can do with bit false?
    for (auto [w, u, v] : edge) {
      if (((w >> bit) & 1) == 0 && (w & req_zero) == 0) {
        join(u, v);
      }
    }
    if (find(0) == find(n - 1)) {
      req_zero |= 1LL << bit;
    } else {
      ans |= 1LL << bit;
    }
    reset();
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}