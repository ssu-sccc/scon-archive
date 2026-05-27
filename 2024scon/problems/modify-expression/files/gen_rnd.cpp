#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(0, 999) * 2 + 1;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        if (i % 2 == 0) cout << (rnd.next(0, 1) ? "T" : "F");
        else cout << (rnd.next(0, 1) ? "&" : "|");
    }
    cout << "\n" << (rnd.next(0, 1) ? "T" : "F") << "\n";
}
