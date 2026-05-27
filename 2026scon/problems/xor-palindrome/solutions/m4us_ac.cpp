#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

constexpr int mod = 1e9 + 7;

ll pw(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod, n >>= 1;
  }
  return res;
}

ll D[10101], DD[10101];

void sol(int tc) {
  int n, m;
  cin >> n >> m;
  vector<ll> v(n);
  int cnt = pw(2, m + 1 >> 1);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    reverse(all(s));
    string t;
    for (int j = 0; j < (m + 1 >> 1); j++)
      t.push_back((s[j] != s[m - j - 1]) + '0');
    for (int j = 0; j < (m + 1 >> 1); j++)
      v[i] |= (t[j] & 1) * (1 << j);
  }

  DD[0] = 1;
  for (ll i : v) {
    for (int j = 0; j < 10101; j++)
      D[j] = DD[j];
    for (int j = 0; j < 10101; j++)
      DD[j] = (D[j] + D[i ^ j]) % mod;
  }
  cout << (DD[0] + mod - 1) % mod << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}