#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n", rnd.next(MIN_N, MAX_N));
    int type = opt<int>("type", 0);

    int x, y;

    if (type == 0) {
        // 완전 랜덤
        x = rnd.next(1, n);
        y = rnd.next(1, n);
        while (y == x) y = rnd.next(1, n);
    }
    else if (type == 1) {
        // 양 끝
        x = 1;
        y = n;
    }
    else if (type == 2) {
        // 인접한 두 위치
        x = rnd.next(1, n - 1);
        y = x + 1;
    }
    else if (type == 3) {
        // 앞쪽에 몰아서
        int lim = max(2, n / 10);
        x = rnd.next(1, lim);
        y = rnd.next(1, lim);
        while (y == x) y = rnd.next(1, lim);
    }
    else if (type == 4) {
        // 뒤쪽에 몰아서
        int lim = max(2, n / 10);
        x = rnd.next(n - lim + 1, n);
        y = rnd.next(n - lim + 1, n);
        while (y == x) y = rnd.next(n - lim + 1, n);
    }
    else if (type == 5) {
        // 정확히 절반 간격 비슷하게
        x = rnd.next(1, n);
        y = x + n / 2;
        if (y > n) y -= n;
        if (y == x) {
            y++;
            if (y > n) y = 1;
        }
    }
    else {
        quitf(_fail, "Unknown type=%d", type);
    }

    cout << n << ' ' << x << ' ' << y << '\n';
    return 0;
}