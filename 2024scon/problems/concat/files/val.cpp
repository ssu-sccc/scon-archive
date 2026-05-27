#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 9, "N"); inf.readEoln();
    vector<int> A = inf.readInts(N, 1, 99, "A"); inf.readEoln();
    vector<int> B = inf.readInts(N, 1, 99, "B"); inf.readEoln();
    inf.readEof();
    return 0;
}