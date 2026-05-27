#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N1 = opt<int>("n1");
    int N2 = opt<int>("n2");
    int N = rnd.next(N1 ? N1 : 1, N2 ? N2 : 5'000'000);
    vector<int> V(N);
    iota(V.begin(), V.end(), 1);
    shuffle(V.begin(), V.end());
    cout << N << "\n";
    for(int i=0; i<N; i++) cout << V[i] << " \n"[i+1==N];
}