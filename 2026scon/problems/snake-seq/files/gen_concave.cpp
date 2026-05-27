#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
// Points on y=C*sqrt(x), concave, slopes decrease
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    long long x = (long long)i * (1000000000LL / n);
    long long y = (long long)(1000000000.0 * sqrt((double)i / n));
    x = max(1LL, x);
    y = max(1LL, y);
    printf("%lld %lld\n", x, y);
  }
}