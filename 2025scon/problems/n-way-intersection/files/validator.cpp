#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(3, 100'000, "N");
    inf.readSpace();
    int M = inf.readInt(2, N, "M");
    inf.readEoln();

    vector<int> A = inf.readInts(N, 1, N, "A");
    assert(set<int>(A.begin(), A.end()).size() == N);
    inf.readEoln();

    inf.readEof();
}