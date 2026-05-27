#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
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
int n;
pi arr[3030];
int dp[3030][3030][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  arr[0] = {0, 0};
  for (int i = 1; i <= n; i++)
    cin >> arr[i].x >> arr[i].y;
  n++;
  sort(arr, arr + n);

  for (int j = 1; j < n; j++)
    dp[0][j][0] = dp[0][j][1] = 1;

  vector<int> l, r, ldp0, ldp1;
  for (int j = 1; j < n; j++) {
    l.clear();
    r.clear();
    for (int i = 0; i < j; i++)
      if (incr(arr[i], arr[j]))
        l.push_back(i);
    for (int i = j + 1; i < n; i++)
      if (incr(arr[j], arr[i]))
        r.push_back(i);
    auto sc = [&](int a, int b) {
      return cmp(arr[a], arr[j], arr[b], arr[j]);
    };
    sort(all(l), sc);
    sort(all(r), sc);
    int lsz = l.size();
    ldp0.resize(lsz);
    ldp1.resize(lsz);
    for (int idx = 0; idx < lsz; idx++) {
      ldp0[idx] = dp[l[idx]][j][0];
      ldp1[idx] = dp[l[idx]][j][1];
    }
    {
      int ptr = 0, mx = 0;
      for (int k : r) {
        while (ptr < lsz && cmp(arr[k], arr[j], arr[l[ptr]], arr[j])) {
          mx = max(mx, ldp1[ptr]);
          ptr++;
        }
        if (mx >= 1)
          dp[j][k][0] = max(dp[j][k][0], mx + 1);
      }
    }
    // DOWN: slope(l→j) > slope(j→k), backward sweep
    // cmp 인자 순서 swap: (l,j,k,j) — 원본은 (k,j,l,j)
    {
      int ptr = lsz - 1, mx = 0;
      for (int ri = (int)r.size() - 1; ri >= 0; ri--) {
        int k = r[ri];
        while (ptr >= 0 && cmp(arr[l[ptr]], arr[j], arr[k], arr[j])) {
          mx = max(mx, ldp0[ptr]);
          ptr--;
        }
        if (mx >= 1)
          dp[j][k][1] = max(dp[j][k][1], mx + 1);
      }
    }
  }

  int ans = min(n - 1, 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans = max(ans, max(dp[i][j][0], dp[i][j][1]));

  cout << ans;
  return 0;
}