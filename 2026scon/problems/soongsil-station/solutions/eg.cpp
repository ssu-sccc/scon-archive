#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n = 3;
  vector<int> a(n);
  for (int &w : a)
    cin >> w;
  int h;
  cin >> h;

  vector<int> id = {0, 1, 2};
  int ans = 1e9;
  do {
    int h0 = h - 1;
    int ret = 0;
    for (int i : id) {
      int w = a[i];
      if (h0 >= w / 2) {
        ret += w / 2;
        h0 -= w / 2;
      } else {
        ret += w;
      }
    }
    ans = min(ans, ret);
  } while (next_permutation(id.begin(), id.end()));
  cout << ans;

  return 0;
}
