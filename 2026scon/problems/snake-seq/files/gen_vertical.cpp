#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
// Points on x=5, vertical line, answer=1
int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  printf("%d\n", n);
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", 5, i);
}
