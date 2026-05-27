#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Lecture {
  int group;
  int pts;
  int ts, te;
};
vector<Lecture> lectures;
vector<bool> used_group;
vector<int> used_lecture;
int totpts = 0;
int ways = 0;

void rec(int i) {
  if (i == lectures.size()) {
    ways += totpts == 22;
    return;
  }
  // can use cur;
  rec(i + 1);
  auto [group, pts, ts, te] = lectures[i];
  if (used_group[group]) return;
  if (totpts + pts > 22) return;
  for (auto i : used_lecture) {
    if (te <= lectures[i].ts) continue;
    if (lectures[i].te <= ts) continue;
    return;
  }
  used_group[group] = true;
  totpts += pts;
  used_lecture.push_back(i);
  rec(i + 1);
  used_group[group] = false;
  totpts -= pts;
  used_lecture.pop_back();
}

int n;

void solve() {
  cin >> n;
  used_group.assign(n, false);
  for (int group = 0; group < n; ++group) {
    int cn;
    cin >> cn;
    while (cn--) {
      int c, d;
      string s, e;
      cin >> c >> d >> s >> e;
      int ts = d;
      ts = ts * 24 + (s[0] - '0') * 10 + (s[1] - '0');
      ts = ts * 60 + (s[3] - '0') * 10 + (s[4] - '0');
      int te = d;
      te = te * 24 + (e[0] - '0') * 10 + (e[1] - '0');
      te = te * 60 + (e[3] - '0') * 10 + (e[4] - '0');
      lectures.push_back({group, c, ts, te});
    }
  }
  used_lecture.reserve(lectures.size());
  rec(0);
  cout << ways << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}