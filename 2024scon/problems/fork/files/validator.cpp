#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 500'000, "N"); inf.readSpace();
    int K = inf.readInt(1, N, "K"); inf.readEoln();
 
    vector<int> A(N);
    for(int i=0;i<N;i++) {
        A[i] = inf.readInt(-500'000, 500'000, "A[" + to_string(i) + "]");
        if(i < N-1) inf.readSpace();
    }
    inf.readEoln();
    
    inf.readEof();
}
