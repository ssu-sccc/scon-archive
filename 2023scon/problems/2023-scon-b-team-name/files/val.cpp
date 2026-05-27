#include "testlib.h"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    vector<int> P(3), Y(3);
    vector<string> S(3);
    for(int i=0; i<3; i++){
        P[i] = inf.readInt(1, 20'000, "P");
        inf.readSpace();
        Y[i] = inf.readInt(2010, 2099, "Y");
        inf.readSpace();
        S[i] = inf.readToken("[A-Z]{1,5}", "S");
        inf.readEoln();
    }
    inf.readEof();
    compress(P); ensuref(P.size() == 3, "P_i dup");
    compress(Y); ensuref(Y.size() == 3, "Y_i dup");
    compress(S); ensuref(S.size() == 3, "S_i dup");
}