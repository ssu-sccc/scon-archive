#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
const int MAX_A = 100000000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(2, MAX_N);
    int b = rnd.next(2, MAX_A - 2);

    vector<int> a(n + 1, b);

    a[1] = b + 2;
    a[2] = b - 1;

    int q = 1;

    int idx = rnd.next(1, n);
    int x = a[idx];

    cout << n << '\n';

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    cout << q << '\n';
    cout << idx << ' ' << x << '\n';

    return 0;
}