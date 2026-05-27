#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll fn(string &s) {
  s.erase(unique(all(s)), s.end());
  if (s.size() == 3) {
    if (s == "CJS")
      return {1, 0};
    else if (s == "JCS")
      return {0, 1};
  }
  return {0, 0};
}

void sol(int tc) {
  int n;
  string s;
  cin >> n >> s;

  string t;
  ll a = 0, b = 0;
  for (char c : s) {
    t += c;
    if (c == 'S') {
      auto [aa, bb] = fn(t);
      a += aa, b += bb;
      t.clear();
    }
  }
  cout << a << endl << b << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}