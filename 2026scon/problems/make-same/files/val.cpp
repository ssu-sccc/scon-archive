#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(MIN_N, MAX_N, "N");
    inf.readEoln();
    inf.readInts(N, MIN_A, MAX_A, "A");
    inf.readEoln();
    int Q = inf.readInt(MIN_Q, MAX_Q, "Q");
    inf.readEoln();
    for (int i = 0; i < Q; i++) {
        inf.readInt(1, N, "i");
        inf.readSpace();
        inf.readInt(MIN_A, MAX_A, "x");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}