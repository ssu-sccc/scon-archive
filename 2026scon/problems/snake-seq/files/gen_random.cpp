#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int MAXC = 1e9;
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int C = MAXC;
  if (argc > 2)
    C = atoi(argv[2]);
  set<pair<int, int>> pts;
  vector<pair<int, int>> res;
  while ((int)res.size() < n) {
    int x = rnd.next(1, C);
    int y = rnd.next(1, C);
    if (pts.insert({x, y}).second)
      res.push_back({x, y});
  }
  printf("%d\n", n);
  shuffle(res.begin(), res.end());
  for (auto &[x, y] : res)
    printf("%d %d\n", x, y);
}