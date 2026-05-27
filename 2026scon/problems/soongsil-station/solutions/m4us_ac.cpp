#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll fn(int a, int b, int c, int bit) {
  ll h = 0, t = 0;
  if (bit & 1)
    h += a / 2, t += a / 2;
  else
    t += a;
  if (bit & 2)
    h += b / 2, t += b / 2;
  else
    t += b;
  if (bit & 4)
    h += c / 2, t += c / 2;
  else
    t += c;
  return {h, t};
}

void sol(int tc) {
  int a, b, c, h;
  cin >> a >> b >> c >> h;
  h--;

  int ans = a + b + c;
  for (int i = 0; i < 8; i++) {
    auto [hh, t] = fn(a, b, c, i);
    if (hh <= h)
      ans = min<int>(t, ans);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}