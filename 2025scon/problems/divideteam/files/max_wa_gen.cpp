#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1'000'000;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int N = rnd.next(MAX / 2, MAX);
    println(N);
    
    vector<int> A(N), B(N);
    
    for (int i = 0; i < N; i++) A[i] = i & 1;
    println(A);
    int tmp = rnd.next(0, MAX);
    for (int i = 0; i < N; i++) B[i] = tmp;
    println(B);
 
    return 0;
}
