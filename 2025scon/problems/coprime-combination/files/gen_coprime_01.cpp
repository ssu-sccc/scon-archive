#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int T = opt<int>(1);
    printf("%d\n", T);
    int n1, r1, n2, r2;
    for (int i = 0; i < T; i++) {
        n1 = rnd.next(1, 5000);
        r1 = rnd.next(0, n1);
        n2 = rnd.next(1, 5000);
        r2 = rnd.next(0, n2);
        printf("%d %d %d %d\n", n1, r1, n2, r2);
    }
}
