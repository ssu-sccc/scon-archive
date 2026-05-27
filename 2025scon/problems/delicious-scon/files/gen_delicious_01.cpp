#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = opt<int>(1);
    int M = opt<int>(2);
    int C = opt<int>(3);
    int D = opt<int>(4);
    printf("%d %d %d %d\n", N, M, C, D);
    vector<int> k(N);
    for (int i = 0; i < N; i++) {
        k[i] = rnd.next(1, M);
        if(i != 0)
            printf(" ");
        printf("%d", k[i]);
    }
    printf("\n");
}
