#include <bits/stdc++.h>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void sol(int tc) {
  int n;
  cin >> n;
  if (n & 1) {
    int x = n >> 1;
    vector<int> v;
    while (x)
      v.push_back(x--);
    while (x < (n + 1 >> 1))
      v.push_back(x++);

    int f = 0;
    for (int i : v) {
      cout << ((i + f) & 1 ? -i : i) << ' ';
      if (i == 0)
        f = 1;
    }
    cout << endl;
  } else {
    cout << 0 << ' ';
    for (int i = 0; i < n / 2 - 1; i++)
      cout << i + 1 << ' ' << -i - 1 << ' ';
    cout << n / 2 << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}