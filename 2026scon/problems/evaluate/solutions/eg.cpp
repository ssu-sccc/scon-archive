#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
ll n, b, arr[202020];
bool f(ll mid) {
  ll ret = 0;
  int cnt = 0;
  priority_queue<ll> pq;
  for (int i = 0; i < n; i++) {
    if (arr[i] < mid) {
      cnt--;
      pq.push(arr[i] - mid);
      if (cnt < 0) {
        ret += -pq.top();
        pq.pop();
        cnt += 2;
      }
    } else
      cnt++;
  }
  return ret <= b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> b;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  ll lo = 0, hi = 2 * 1e9, ans = 0;
  while (lo <= hi) {
    ll mid = lo + hi >> 1;
    if (f(mid))
      lo = mid + 1, ans = mid;
    else
      hi = mid - 1;
  }
  cout << ans;
  return 0;
}
