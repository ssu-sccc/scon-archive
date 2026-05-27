#include <bits/stdc++.h>
#include <functional>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, B, A[202020];

bool fn(int t) {
  ll credit = 0, b = B;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 1; i <= N; i++) {
    if (A[i] >= t)
      credit++;
    else
      credit--, pq.push(t - A[i]);
    if (credit < 0) {
      b -= pq.top();
      credit += 2;
      pq.pop();
    }
  }
  return b >= 0;
}

void sol(int tc) {
  cin >> N >> B;
  for (int i = 1; i <= N; i++)
    cin >> A[i];

  int l = 1, r = 2e9;
  while (l < r) {
    ll m = l + r + 1 >> 1;
    if (fn(m))
      l = m;
    else
      r = m - 1;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}