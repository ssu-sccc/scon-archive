#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, M, Q, A[101010], DD[101010];
vector<int> G[101010], D[101010];

void sol(int tc) {
  cin >> N >> M >> Q;
  for (int i = 0, u, v; i < M; i++) {
    cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
    DD[u]++, DD[v]++;
  }
  for (int i = 1; i <= N; i++) {
    for (int j : G[i])
      D[i].push_back(DD[j]);
  }

  for (ll i = 0, op, u, x, d; i < Q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> u >> x;
      for (int d : D[u])
        A[d] += x;
    } else {
      cin >> d;
      cout << A[d] << endl;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}
