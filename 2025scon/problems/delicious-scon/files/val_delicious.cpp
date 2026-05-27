#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 200, "N");
    inf.readSpace();
    int M = inf.readInt(1, 25000, "M");
    inf.readSpace();
    int C = inf.readInt(1, M, "C");
    inf.readSpace();
    int D = inf.readInt(1, M, "D");
    ensure(C <= D);
    ensuref(D % C == 0, "D is not a multiple of C");
    inf.readEoln();
    for (int i = 1; i <= N; i++) {
        if(i != 1)
            inf.readSpace();
        inf.readInt(1, M, "k_"+to_string(i));
    }
    inf.readEoln();
    inf.readEof();
}