#include "testlib.h"
#include "jhnah917.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N1 = opt<int>("n1"), N2 = opt<int>("n2");
    int M1 = opt<int>("m1"), M2 = opt<int>("m2");
    int W1 = opt<int>("w1"), W2 = opt<int>("w2");
    int N = rnd.next(N1 ? N1 : 2, N2 ? N2 : 2000);
    int M = rnd.next(max(N-1, M1 ? M1 : 1), M2 ? M2 : 5000);
    int S = rnd.next(1, N);
    auto E = graph_gen::make_undirected_connected_graph(N, M);
    graph_gen::shuffle_edge(E, false);
    graph_gen::relabel_vertex(N, E);
    vector<int> A(N); iota(A.begin(), A.end(), 1); shuffle(A.begin(), A.end());

    cout << N << " " << M << " " << S << "\n";
    for(auto [u,v] : E) cout << min(u,v) << " " << max(u,v) << " " << rnd.next(W1 ? W1 : 1, W2 ? W2 : 5000) << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    return 0;
}