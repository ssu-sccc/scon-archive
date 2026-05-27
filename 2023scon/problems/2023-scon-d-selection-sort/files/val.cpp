#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 500'000, "N"); inf.readEoln();
    vector<int> V = inf.readInts(N, 1, N, "A"); inf.readEoln();
    inf.readEof();
    sort(V.begin(), V.end());
    for(int i=0; i<N; i++) ensuref(V[i] == i + 1, "not permutation");
}