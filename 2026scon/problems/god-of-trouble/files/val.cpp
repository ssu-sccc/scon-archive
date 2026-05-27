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
    
    inf.readInts(133, 0, 3, "change");
    inf.readEoln();
    
    inf.readEof();
    return 0;
}