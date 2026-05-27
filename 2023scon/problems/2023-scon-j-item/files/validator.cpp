#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
const long long MAXX = 1e18;
 
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 200'000, "N"); inf.readEoln();
    
    for(int i=0;i<N;i++) {
        int a = inf.readLong(0, MAXX, "X[" + to_string(i) + "]");
        if(i+1 == N)
            inf.readEoln();
        else
            inf.readSpace();
    }
 
    inf.readEof();
}
