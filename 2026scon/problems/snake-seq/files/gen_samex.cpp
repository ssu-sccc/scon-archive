#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const long long MAXC = 1e9;
// Many points sharing x values
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int xcount = max(1, n / 10);
  vector<long long> xs;
  set<long long> xset;
  while ((int)xs.size() < xcount) {
    long long x = rnd.next(1LL, MAXC);
    if (xset.insert(x).second)
      xs.push_back(x);
  }
  set<pair<long long, long long>> pts;
  vector<pair<long long, long long>> res;
  while ((int)res.size() < n) {
    long long x = xs[rnd.next(0, xcount - 1)];
    long long y = rnd.next(1LL, MAXC);
    if (pts.insert({x, y}).second)
      res.push_back({x, y});
  }
  printf("%d\n", n);
  shuffle(res.begin(), res.end());
  for (auto &[x, y] : res)
    printf("%lld %lld\n", x, y);
}