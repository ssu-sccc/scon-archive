#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
// Points on y=2x, all collinear, answer=2
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  printf("%d\n", n);
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", i, 2 * i);
}