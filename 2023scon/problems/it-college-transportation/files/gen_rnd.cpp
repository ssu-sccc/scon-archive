#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int a = __testlib_opts.count("a") ? opt<int>("a") : rnd.next(1, 1'000'000);
    int b = __testlib_opts.count("b") ? opt<int>("b") : rnd.next(1, 1'000'000);
    int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(1, b);
    cout << n << " " << a << " " << b << "\n";
}
