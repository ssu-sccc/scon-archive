#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // mode:
    // 0 = n 고정
    // 1 = n 을 [1, n] 에서 랜덤
    int mode = opt<int>("mode", 0);

    int n;
    int k = opt<int>("n", MAXN);
    
    if (mode == 1) {
        n = rnd.next(1, k);
    } else n = k;

    // type:
    // 0 = 완전 랜덤
    // 1 = 전부 0
    // 2 = 전부 1
    // 3 = 010101...
    // 4 = 101010...
    int type = opt<int>("type", 0);

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        int x = 0;
        if (type == 0) x = rnd.next(0, 1);
        else if (type == 1) x = 0;
        else if (type == 2) x = 1;
        else if (type == 3) x = (i & 1);
        else if (type == 4) x = ((i + 1) & 1);
        else quitf(_fail, "unknown type");

        cout << x;
    }
    cout << '\n';
    return 0;
}