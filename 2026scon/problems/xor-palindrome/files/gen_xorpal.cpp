#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = opt<int>(1);
    int M = opt<int>(2);
    printf("%d %d\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d", rnd.next(0, 1));
        printf("\n");
    }
}
