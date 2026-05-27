#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int A = rnd.next(1, 100) * 2;
    int B = rnd.next(1, 100) * 2;
    int C = rnd.next(1, 100) * 2;
    int H = rnd.next(1, 200);
    printf("%d %d %d\n", A, B, C);
    printf("%d\n", H);
}
