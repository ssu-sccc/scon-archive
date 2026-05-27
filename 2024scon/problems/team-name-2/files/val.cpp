#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

bool condition1(string s){
    int up = 0, lo = 0;
    for(auto c : s){
        if(isupper(c)) up++;
        if(islower(c)) lo++;
    }
    return up <= lo;
}

bool condition2(string s){
    return s.size() <= 10;
}

bool condition3(string s){
    for(auto c : s) if(!isdigit(c)) return true;
    return false;
}

bool check(string s){
    return condition1(s) && condition2(s) && condition3(s);
}

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100, "N"); inf.readEoln();
    int C = 0;
    for(int i=1; i<=N; i++){
        string S = inf.readToken("[a-zA-Z0-9\\-]{1,20}", "S");
        inf.readEoln();
        C += check(S);
    }
    ensure(C == 1);
    inf.readEof();
    return 0;
}