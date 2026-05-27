#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
  int64_t n, s, e;
  cin >> n >> s >> e;
  if (s > e) swap(s, e);
  // n + s - e - 2
  pair<int, int> opt{(s - 1) + (n - 1) + (n - e), 0};
  // n - s + s - s + e - 3 = n - s + e - 3
  opt = min(opt, {(s - 1) + (n - (s + 1)) + (e - (s + 1)) + 1, 1});
  opt = min(opt, {((e - 1) - s) + 1 + ((s - 1) - 1) + 1 + (n - e), 2});
  cout << opt.second << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}