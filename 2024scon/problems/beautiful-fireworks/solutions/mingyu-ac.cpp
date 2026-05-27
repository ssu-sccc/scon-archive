#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> adj;
vector<int64_t> sz;
int64_t szsum = 0, cur = 0, ans = 0;

void dfs(int node, int par = -1) {
  for (auto& v : adj[node]) {
    if (v == par) continue;
    dfs(v, node);
    sz[node] += sz[v];
  }
  cur += sz[node];
}
void dfs2(int node, int par = -1) {
  for (auto& v : adj[node]) {
    if (v == par) continue;
    // reroot
    cur += szsum - 2 * sz[v];
    dfs2(v, node);
    cur -= szsum - 2 * sz[v];
  }
  ans = max(ans, cur);
}

void solve() {
  cin >> n;
  adj.assign(n, {});
  sz.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  for (auto& s : sz) cin >> s, szsum += s;
  dfs(0);
  cur -= szsum;
  dfs2(0);
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