#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int p[500500]; 
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(2, 300'000, "N"); inf.readSpace();
    int M = inf.readInt(N-1, 300'000, "M"); inf.readEoln();
 
    iota(p+1, p+1+N, 1);
    set<array<int, 2>> s;
    for(int i=0;i<M;i++) {
        int X = inf.readInt(1, N, "X"); inf.readSpace();
        int Y = inf.readInt(1, N, "Y"); inf.readSpace();
        long long Z = inf.readLong(0, (1ll << 60)-1, "Z"); inf.readEoln();

        ensuref(X != Y, "X != Y");
        p[find(X)] = find(Y);

        if(X > Y) swap(X, Y);
        s.insert({X, Y});
    }

    ensuref(s.size() == M, "No duplicated edges");
    
    for(int i=2;i<=N;i++) ensuref(find(1) == find(i), "Graph must be connected");
    
    inf.readEof();
}
