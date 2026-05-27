#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int n = 65537;
    const int q = 1;
    const int c = 65537;
    const int d = 65536;

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        int x = c;
        if (i == 0) x += d;        // A1 = 131073
        if (i == n - 1) x -= d;    // AN = 1
        cout << x << (i + 1 == n ? '\n' : ' ');
    }

    cout << q << '\n';

    // no-op query
    cout << 1 << ' ' << (c + d) << '\n';

    return 0;
}