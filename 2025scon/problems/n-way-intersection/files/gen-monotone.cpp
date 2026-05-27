#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("N"), M = opt<int>("M"), flag = opt<int>("flag");
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    
    if(flag == 1) reverse(A.begin(), A.end());
    if(flag == 2) reverse(A.begin()+N/2, A.end());
    if(flag == 3) reverse(A.begin(), A.begin()+N/2);
    
    cout << N << " " << M << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    return 0;
}