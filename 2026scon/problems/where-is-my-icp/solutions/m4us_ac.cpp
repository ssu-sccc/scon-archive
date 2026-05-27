#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void sol(int tc) {
  int n, m;
  string s, t;
  cin >> n >> s >> m >> t;
  map<char, int> a;
  for (char c : s)
    a[c]++;
  for (char c : t)
    a[c]++;

  if (a['I'] >= 1 && a['C'] > 1 && a['P'] >= 1)
    cout << "m4us happy" << endl;
  else
    cout << "m4us sad" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}