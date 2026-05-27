#include <algorithm>
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void sol(int tc) {
  int n;
  string s, t, a;
  cin >> n >> s;
  t = s;
  t.erase(unique(all(t)), t.end());
  int i = 0;
  for (char c : s) {
    if (i == t.size())
      continue;
    if (c == t[i]) {
      i++;
      a += c;
    } else if (c < t[i]) {
      a += c;
    }
  }
  cout << a << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}