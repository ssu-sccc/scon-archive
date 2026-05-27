#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int M = opt<int>(1), N = 1 << M;
    printf("%d %d\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--)
            printf("%d", (i >> j) & 1);
        printf("\n");
    }
}