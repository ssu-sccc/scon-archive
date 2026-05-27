#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readSpace();
    int x = inf.readInt(1, n, "x");
    inf.readSpace();
    int y = inf.readInt(1, n, "y");
    inf.readEoln();

    ensuref(x != y, "x and y must be distinct, but both are %d", x);

    inf.readEof();
    return 0;
}