#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using us = unsigned short;

struct P {
  ll x, y;
  bool operator<(const P& o) const {
    if (x != o.x) return x < o.x;
    return y < o.y;
  }
};

inline bool incr(const P& a, const P& b) {
  return a.x < b.x && a.y < b.y;
}

inline bool cmp(const P& a, const P& b, const P& c, const P& d) {
  return (a.y - b.y) * (c.x - d.x) < (c.y - d.y) * (a.x - b.x);
}

const int MAXN = 3030;
const int LIM = 150;

int n;
us dp[2][MAXN][MAXN];
P arr[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  arr[0] = {0, 0};
  for (int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y;
  sort(arr, arr + n + 1);

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    dp[0][0][i] = 1;
    dp[1][0][i] = 1;
  }

  for (int j = 1; j <= n; j++) {
    for (int k = j + 1; k <= n; k++) {
      if (!incr(arr[j], arr[k])) continue;

      if (cmp(arr[j], arr[0], arr[k], arr[j])) {
        us cand = dp[1][0][j] + 1;
        if (dp[0][j][k] < cand) dp[0][j][k] = cand;
      }
      if (cmp(arr[k], arr[j], arr[j], arr[0])) {
        us cand = dp[0][0][j] + 1;
        if (dp[1][j][k] < cand) dp[1][j][k] = cand;
      }

      for (int i = j - 1, cnt = 0; i >= 1 && cnt < LIM - 1; i--, cnt++) {
        if (!incr(arr[i], arr[j])) continue;
        if (!dp[0][i][j] && !dp[1][i][j]) continue;

        if (cmp(arr[j], arr[i], arr[k], arr[j])) {
          us cand = dp[1][i][j] + 1;
          if (dp[0][j][k] < cand) dp[0][j][k] = cand;
        }
        if (cmp(arr[k], arr[j], arr[j], arr[i])) {
          us cand = dp[0][i][j] + 1;
          if (dp[1][j][k] < cand) dp[1][j][k] = cand;
        }
      }

      ans = max<int>(ans, dp[0][j][k]);
      ans = max<int>(ans, dp[1][j][k]);
    }
  }

  cout << ans;
  return 0;
}