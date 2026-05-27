#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool qry(int l, int r) {
  if (l > r)
    return 0;
  cout << "? " << r - l + 1 << ' ';
  for (int i = l; i <= r; i++)
    cout << i << ' ';
  cout << endl;
  int x;
  cin >> x;
  return x;
}

void sol(int tc) {
  int n;
  cin >> n;

  int x, y, l = 1, r = n;

  while (l < r) {
    int m = l + r >> 1;
    if (qry(l, m))
      r = m;
    else
      l = m + 1;
  }
  x = r;

  if (qry(1, x - 1))
    l = 1, r = x - 1;
  else
    l = x + 1, r = n;
  while (l < r) {
    int m = l + r >> 1;
    if (qry(l, m))
      r = m;
    else
      l = m + 1;
  }
  y = r;
  cout << "! " << x << ' ' << y << endl;
}

int main() {
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}