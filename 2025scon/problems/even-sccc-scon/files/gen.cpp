#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int mn = __testlib_opts.count("mn") ? opt<int>("mn") : 1, mx = __testlib_opts.count("mx") ? opt<int>("mx") : 1'000'000;
    int n = rnd.next(mn,mx);
    cout << n << '\n';
    return 0;
}