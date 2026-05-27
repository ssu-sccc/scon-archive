#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
  int64_t n, s, e;
  cin >> n >> s >> e;
  if ((s == 1 && e == n) || (s == n && e == 1)) {
    cout << "0\n";
  } else if ((s == 1) || (s == n) || (e == s + 1) || (s == e + 1)) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }
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