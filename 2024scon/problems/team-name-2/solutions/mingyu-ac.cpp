#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
  string s;
  cin >> s;
  if (s.length() > 10) return;
  int ucnt = accumulate(s.begin(), s.end(), 0,
                        [&](int a, char b) { return a + (isupper(b) != 0); });
  int lcnt = accumulate(s.begin(), s.end(), 0,
                        [&](int a, char b) { return a + (islower(b) != 0); });
  if (ucnt > lcnt) return;
  int ndcnt = accumulate(s.begin(), s.end(), 0,
                         [&](int a, char b) { return a + (isdigit(b) == 0); });
  if (ndcnt == 0) return;
  cout << s << "\n";
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