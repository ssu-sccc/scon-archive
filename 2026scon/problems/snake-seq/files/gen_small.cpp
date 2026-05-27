#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const long long MAXC = 1e9;
// Many points sharing y values
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int ycount = max(1, n / 10);
  vector<long long> ys;
  set<long long> yset;
  while ((int)ys.size() < ycount) {
    long long y = rnd.next(1LL, MAXC);
    if (yset.insert(y).second)
      ys.push_back(y);
  }
  set<pair<long long, long long>> pts;
  vector<pair<long long, long long>> res;
  while ((int)res.size() < n) {
    long long x = rnd.next(1LL, MAXC);
    long long y = ys[rnd.next(0, ycount - 1)];
    if (pts.insert({x, y}).second)
      res.push_back({x, y});
  }
  printf("%d\n", n);
  shuffle(res.begin(), res.end());
  for (auto &[x, y] : res)
    printf("%lld %lld\n", x, y);
}