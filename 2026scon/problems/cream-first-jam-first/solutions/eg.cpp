#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  string s;
  cin >> n >> s;
  string str;
  int ans0 = 0, ans1 = 0;
  for (int i = 0; i < n;) {
    int j = i + 1;
    if (s[i] == 'S') {
      str.push_back('S');
      if (str == "CJS")
        ans0++;
      else if (str == "JCS")
        ans1++;
      str = "";
    } else {
      while (j < n && s[i] == s[j])
        j++;
      str.push_back(s[i]);
    }
    i = j;
  }

  cout << ans0 << " " << ans1;
  return 0;
}
