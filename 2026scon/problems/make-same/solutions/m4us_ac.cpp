#include <bits/stdc++.h>
#include <numeric>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define endl '\n'
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, Q, A[202020], T;

bool fn(ll sum, ll psum) {
  if (sum % N == 0) {
    ll x = sum / N;
    return psum == x * T;
  }
  return 0;
}

void sol(int tc) {
  cin >> N;
  T = N * (N + 1) / 2;
  ll sum = 0, psum = 0;
  for (int i = 1; i <= N; i++)
    cin >> A[i], sum += A[i], psum += sum;

  cout << (fn(sum, psum) ? "Yes" : "No") << endl;

  cin >> Q;
  for (int i = 1, j, x; i <= Q; i++) {
    cin >> j >> x;
    ll del = x - A[j];
    A[j] += del;
    psum += (N - j + 1) * del;
    sum += del;
    cout << (fn(sum, psum) ? "Yes" : "No") << endl;
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