#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;

void solve() {
  cin >> n;
  string s, t;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    s += to_string(tmp);
  }
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    t += to_string(tmp);
  }
  if (s.length() != t.length()) {
    if (s.length() > t.length())
      cout << t << "\n";
    else
      cout << s << "\n";
  } else {
    if (s < t)
      cout << s << "\n";
    else
      cout << t << "\n";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}