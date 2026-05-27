#include <bits/stdc++.h>

using namespace std;

int t[100];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  string a, b;
  cin >> n >> a >> m >> b;
  for (char c : a)
    t[c]++;
  for (char c : b)
    t[c]++;

  bool f = t['I'] >= 1 && t['C'] >= 2 && t['P'] >= 1;
  cout << (f ? "m4us happy" : "m4us sad");
  return 0;
}
