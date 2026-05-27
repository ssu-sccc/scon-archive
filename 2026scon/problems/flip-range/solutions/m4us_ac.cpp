#include <bits/stdc++.h>
#include <numeric>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void sol(int tc) {
  int n;
  string s;
  cin >> n >> s;

  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int f = ((i & 1 ? '1' : '0') != s[i]);
    if (a.size() && a.back() == f)
      continue;
    else
      a.push_back(f);
  }
  for (int i = 0; i < n; i++) {
    int f = ((i & 1 ? '0' : '1') != s[i]);
    if (b.size() && b.back() == f)
      continue;
    else
      b.push_back(f);
  }
  cout << min(accumulate(all(a), 0), accumulate(all(b), 0)) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}