#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const long long MAXC = 1e9;
// Random points with coordinates near 10^9
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  long long lo = 1, hi = MAXC;
  set<pair<long long, long long>> pts;
  vector<pair<long long, long long>> res;
  while ((int)res.size() < n) {
    long long x = rnd.next(lo, hi);
    long long y = rnd.next(lo, hi);
    if (pts.insert({x, y}).second)
      res.push_back({x, y});
  }
  printf("%d\n", n);
  shuffle(res.begin(), res.end());
  for (auto &[x, y] : res)
    printf("%lld %lld\n", x, y);
}