#include "testlib.h"
#include "jhnah917.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(2, 2000, "N"); inf.readSpace();
    int M = inf.readInt(N-1, 5000, "M"); inf.readSpace();
    int S = inf.readInt(1, N, "S"); inf.readEoln();
    vector<pair<int,int>> E;
    for(int i=1; i<=M; i++){
        int u = inf.readInt(1, N-1, "u"); inf.readSpace();
        int v = inf.readInt(u+1, N, "v"); inf.readSpace();
        int w = inf.readInt(1, 5000, "w"); inf.readEoln();
        E.emplace_back(u, v);
    }
    ensuref(graph_val::is_undirected_connected_graph(N, E), "connect");
    vector<int> A = inf.readInts(N, 1, N, "A"); inf.readEoln();
    inf.readEof();
    sort(A.begin(), A.end());
    for(int i=0; i<N; i++) ensuref(A[i] == i + 1, "perm");
}