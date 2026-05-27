#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> Gen(int n, int len){
    assert(len == 0 || n <= len && len <= n+n);
    
    vector<int> res(n);
    if(len == 0){
        for(int i=0; i<n; i++) res[i] = rnd.next(1, 99);
        return res;
    }
    
    for(int i=0; i<n; i++) res[i] = rnd.next(1, 9);
    len -= n;
    
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    shuffle(ord.begin(), ord.end());
    for(int i=0; i<len; i++) res[ord[i]] = res[ord[i]] * 10 + rnd.next(0, 9);
    
    return res;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("n"), AL = opt<int>("a"), BL = opt<int>("b");
    vector<int> A = Gen(N, AL), B = Gen(N, BL);
    cout << N << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    for(int i=0; i<N; i++) cout << B[i] << " \n"[i+1==N];
    return 0;
}