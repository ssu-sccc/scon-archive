#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int T = inf.readInt(1, 10'000, "T"); inf.readEoln();
    for(int i=1;i<=T;i++) {
        int N = inf.readInt(2, 1'000'000'000, "N"); inf.readSpace();
        int S = inf.readInt(1, N, "S"); inf.readSpace();
        int E = inf.readInt(1, N, "E"); inf.readEoln();
    
        ensuref(S != E, "Start and End needs to be different");
    }
    inf.readEof();
}
