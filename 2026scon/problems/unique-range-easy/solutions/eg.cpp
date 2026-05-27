#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> ans = {0};
  for (int i = 1; i < n; i++) {
    int t = (i + 1) / 2;
    if (i % 2)
      t *= -1;
    ans.push_back(t);
  }
  for (int w : ans)
    cout << w << " ";
  return 0;
}
