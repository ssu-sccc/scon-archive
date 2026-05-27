#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const long long MAXC = 1e9;
// sqrt(n) x sqrt(n) grid points
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int side = (int)ceil(sqrt((double)n));
  long long gap = rnd.next(1LL, MAXC / max(1, side));
  long long span = (side - 1) * gap;
  long long ox = rnd.next(1LL, MAXC - span);
  long long oy = rnd.next(1LL, MAXC - span);
  vector<pair<long long, long long>> all;
  for (int i = 0; i < side; i++)
    for (int j = 0; j < side; j++)
      all.push_back({ox + i * gap, oy + j * gap});
  shuffle(all.begin(), all.end());
  n = min(n, (int)all.size());
  printf("%d\n", n);
  for (int i = 0; i < n; i++)
    printf("%lld %lld\n", all[i].first, all[i].second);
}