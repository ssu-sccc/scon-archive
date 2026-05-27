#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
int64_t cur = 0, m;

void solve() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int delta;
    cin >> delta;
    cur += delta;
    cur = max(cur, (int64_t)0);
    cnt += cur >= m;
  }
  cout << cnt << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}