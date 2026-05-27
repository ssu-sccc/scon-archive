#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int MINA = -1e9;
const int MAXA = 1e9;
 
int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100'000, "N"); inf.readEoln();
    
    for(int i=0;i<N;i++) {
        int a = inf.readInt(MINA, MAXA, "A[" + to_string(i) + "]");
        if(i+1 == N)
            inf.readEoln();
        else
            inf.readSpace();
    }

    inf.readEof();
}
