#include "testlib.h"
#include "jhnah917.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N1 = opt<int>("n1"), N2 = opt<int>("n2");
    int N = rnd.next(N1 ? N1 : 2, N2 ? N2 : 2000), M = 5000;
    int S = rnd.next(1, N);
    vector<pair<int,int>> E; E.reserve(M);
    for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++) E.emplace_back(i, j);
    while(E.size() < M){
        int u = rnd.next(1, N-1);
        int v = rnd.next(u+1, N);
        E.emplace_back(u, v);
    }
    graph_gen::shuffle_edge(E, false);
    vector<int> A(N); iota(A.begin(), A.end(), 1); shuffle(A.begin(), A.end());

    cout << N << " " << M << " " << S << "\n";
    for(auto [u,v] : E) cout << min(u,v) << " " << max(u,v) << " " << rnd.next(1, 5000) << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    return 0;
}