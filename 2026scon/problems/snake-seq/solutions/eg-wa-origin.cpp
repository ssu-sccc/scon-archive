#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll, ll> pi;
#define x first
#define y second

pi operator-(pi a, pi b) { return pi(a.x - b.x, a.y - b.y); }
bool incr(pi a, pi b) { return a.x < b.x && a.y < b.y; }

bool slope(pi a, pi b, pi c) {
  return a.y * b.x < b.y * a.x;
}

int n, dp[2][3030][3030], ldp[3030];
pi arr[3030];
vector<int> li, ri;

void fillDP(int j) {
  auto cmp = [&](int a, int b) -> bool {
    return slope(arr[a], arr[b], arr[j]);
  };

  li.clear();
  ri.clear();
  for (int i = 0; i < n; i++)
    if (incr(arr[i], arr[j]))
      li.push_back(i);
  for (int i = j + 1; i <= n; i++)
    if (incr(arr[j], arr[i]))
      ri.push_back(i);
  sort(all(li), cmp);
  sort(all(ri), cmp);
  int lsz = li.size();
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < lsz; i++)
      ldp[i] = dp[t ^ 1][li[i]][j];

    int p = 0, mx = 0;
    for (int r : ri) {
      while (p < lsz && (t ? cmp(li[p], r) : cmp(r, li[p]))) {
        mx = max(mx, ldp[p]);
        p++;
      }
      if (mx >= 1)
        dp[t][j][r] = max(dp[t][j][r], mx + 1);
    }
    reverse(all(li));
    reverse(all(ri));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i].x >> arr[i].y;
  sort(arr, arr + n + 1);

  for (int i = 1; i <= n; i++)
    dp[0][0][i] = dp[1][0][i] = 1;

  for (int i = 1; i <= n; i++)
    fillDP(i);

  int ans = 1;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, *max_element(dp[0][i], dp[0][i] + n + 1));
    ans = max(ans, *max_element(dp[1][i], dp[1][i] + n + 1));
  }

  cout << ans;
  return 0;
}