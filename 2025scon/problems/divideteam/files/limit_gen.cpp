#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int N = 1'000'000;
    println(N);
    
    vector<int> A(N), B(N);
    
    for (int i = 0; i < N; i++) A[i] = i & 1;
    println(A);
    
    for (int i = 0; i < N; i++) B[i] = (i & 1 ? 1000000 : 0);
    println(B);
 
    return 0;
}
