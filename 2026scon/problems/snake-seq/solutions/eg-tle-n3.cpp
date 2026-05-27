#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
#define x first
#define y second
pi operator-(pi a, pi b) { return pi(a.x - b.x, a.y - b.y); }
bool incr(pi a, pi b) { return a.x < b.x && a.y < b.y; }
bool cmp(pi a, pi b, pi c, pi d) {
  pi da = a - b;
  pi db = c - d;
  return da.y * db.x < db.y * da.x;
}
int n, dp[2][3030][3030];
pi arr[3030];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i].x >> arr[i].y;
  sort(arr, arr + n + 1);
  for (int i = 1; i <= n; i++)
    dp[0][0][i] = dp[1][0][i] = 1;
  for (int j = 1; j <= n; j++) {
    for (int k = j + 1; k <= n; k++) {
      if (!incr(arr[j], arr[k]))
        continue;
      for (int i = 0; i < j; i++) {
        if (!incr(arr[i], arr[j]))
          continue;
        if (!dp[0][i][j] && !dp[1][i][j])
          continue;
        if (cmp(arr[j], arr[i], arr[k], arr[j]))
          dp[0][j][k] = max(dp[0][j][k], dp[1][i][j] + 1);
        if (cmp(arr[k], arr[j], arr[j], arr[i]))
          dp[1][j][k] = max(dp[1][j][k], dp[0][i][j] + 1);
      }
    }
  }
  int ans = min(n - 1, 1);
  for (int i = 0; i <= n; i++) {
    ans = max(ans, *max_element(dp[0][i], dp[0][i] + n + 1));
    ans = max(ans, *max_element(dp[1][i], dp[1][i] + n + 1));
  }
  cout << ans;
  return 0;
}