#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("N"), M = rnd.next(2, N);
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    shuffle(A.begin(), A.end());
    cout << N << " " << M << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    return 0;
}