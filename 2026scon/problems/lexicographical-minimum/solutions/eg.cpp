#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pi;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  string str;
  cin >> n >> str;

  vector<pi> v;
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && str[i] == str[j])
      j++;
    v.push_back(pi(str[i], j - i));
    i = j;
  }

  string ans;
  for (int i = 0; i < v.size(); i++) {
    if (i + 1 < v.size()) {
      if (v[i].first < v[i + 1].first) {
        while (v[i].second--)
          ans.push_back(v[i].first);
      } else {
        ans.push_back(v[i].first);
      }
    } else {
      ans.push_back(v[i].first);
    }
  }
  cout << ans;
  return 0;
}
