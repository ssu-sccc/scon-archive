#include <bits/stdc++.h>
using namespace std;

int f(vector<int> v) {
  int n = v.size();
  int ans = 0;

  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && v[j] == v[i] + j - i)
      j++;
    ans++;
    i = j;
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  string s;
  cin >> n >> s;

  vector<int> v[2];
  for (int i = 0; i < n; i++) {
    int t = s[i] - '0';
    if (t != i % 2)
      v[0].push_back(i);
    if (t != (i + 1) % 2)
      v[1].push_back(i);
  }

  cout << min(f(v[0]), f(v[1]));
  return 0;
}
