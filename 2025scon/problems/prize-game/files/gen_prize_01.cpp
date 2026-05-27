#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = opt<int>(1);
    printf("%d\n", N);
    int n1, n2, n3;
    for (int i = 0; i < N; i++) {
        n1 = rnd.next(1, 100);
        n2 = rnd.next(1, 100);
        while (n1 == n2)
            n2 = rnd.next(1, 100);
        n3 = rnd.next(1, 100);
        while (n1 == n3 || n2 == n3)
            n3 = rnd.next(1, 100);
        printf("%d %d %d\n", n1, n2, n3);
    }
}
