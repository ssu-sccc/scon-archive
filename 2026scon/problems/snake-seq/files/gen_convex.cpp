#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
// Zigzag slopes (2,1,2,1,...), answer=N
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  printf("%d\n", n);
  long long y = 0;
  for (int i = 1; i <= n; i++) {
    y += (i % 2 == 1) ? 2 : 1;
    printf("%d %lld\n", i, y);
  }
}