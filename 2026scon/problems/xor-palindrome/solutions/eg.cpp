#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
int dp[50505][1 << 10], n, m, arr[50505];
int f(int pos, int st) {
  if (pos == n)
    return st == 0;
  int &ret = dp[pos][st];
  if (ret != -1)
    return ret;
  ret = 0;
  ret = (ret + f(pos + 1, st)) % mod;
  ret = (ret + f(pos + 1, st ^ arr[pos])) % mod;

  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int sz = s.size();
    for (int j = 0; j < sz / 2; j++) {
      if (s[j] != s[sz - j - 1])
        arr[i] |= (1 << j);
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << (f(0, 0) - 1 + mod) % mod;
  return 0;
}
