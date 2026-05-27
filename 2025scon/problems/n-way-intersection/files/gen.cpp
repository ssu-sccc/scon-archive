#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int N = opt<int>(1);
    int M = opt<int>(2);

    cout << N << " " << M << "\n";

    vector<int> A(N);

    for(int i = 0; i < N; i++) A[i] = i+1;
 
    for(int i = 0; i < N; i++) {
        int r = rnd.next(0, N-1);
        swap(A[i], A[r]);
    }

    for(int i = 0; i < N; i++) cout << A[i] << " \n"[i==N-1];

    return 0;
}