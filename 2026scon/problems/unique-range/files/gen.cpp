#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n", -1);;
    if (n == -1) n = rnd.next(opt<int>("l", 1), opt<int>("r", MAX_N));
    
    cout << n << '\n';
    return 0;
}