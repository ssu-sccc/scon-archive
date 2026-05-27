#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(1, 3'000, "n");
  inf.readEoln();

  set<pair<int, int>> pts;
  for (int i = 0; i < n; i++) {
    int x = inf.readInt(1, 1'000'000'000, "x");
    inf.readSpace();
    int y = inf.readInt(1, 1'000'000'000, "y");
    inf.readEoln();
    ensuref(pts.insert({x, y}).second, "Duplicate point (%d, %d)", x, y);
  }
  inf.readEof();
  return 0;
}