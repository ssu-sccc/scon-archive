#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, k;
vector<int64_t> dpp{0};
vector<int64_t> dpp_pfxmax{0};

void solve() {
  cin >> n >> k;
  dpp.assign(k, 0);
  dpp_pfxmax.assign(k, 0);
  int64_t asum = 0;
  auto add = [&](int a) {
    asum += a;
    dpp.push_back(max(dpp.back() - a, dpp_pfxmax[dpp_pfxmax.size() - k]));
    dpp_pfxmax.push_back(max(dpp_pfxmax.back(), dpp.back()));
  };
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    add(a);
  }
  for (int i = 0; i < k; ++i) add(0);
  cout << dpp.back() + asum << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}