#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;

void solve() {
  cin >> n;
  vector<int> a, b;
  for (int i = n; i > 0; i -= 3) {
    a.push_back(i);
    if (i > 1) b.push_back(i - 1);
    if (i > 2) b.push_back(i - 2);
  }
  if (n % 3 == 1) a.pop_back();
  cout << a.size() << "\n";
  for (auto a : a) cout << a << " ";
  cout << "\n" << b.size() << "\n";
  for (auto b : b) cout << b << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}