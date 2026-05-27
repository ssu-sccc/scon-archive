#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;

void solve() {
  cin >> n;
  //   op -> |, !op -> &
  bool pval = false, val = false, op = true, llit = false;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;

    switch (c) {
      case 'T':
        pval = val;
        if (op) val = true;
        llit = true;
        break;
      case 'F':
        pval = val;
        if (!op) val = false;
        llit = false;
        break;
      case '&':
        op = false;
        break;
      case '|':
        op = true;
        break;
    }
  }
  char reqc;
  cin >> reqc;
  bool req = reqc == 'T';
  if (req == val) {
    cout << "0\n";
    return;
  }
  if (n == 1) {
    cout << "1\n";
    return;
  }
  if (req) {
    if (!pval && !op && !llit) {
      // (F) & F
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  } else {
    if (pval && op && llit) {
      // (T) | T
      cout << "2\n";
    } else {
      cout << "1\n";
    }
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