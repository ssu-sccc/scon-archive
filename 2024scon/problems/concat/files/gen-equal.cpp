#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> Gen(int n, string s){
    vector<int> len(n, 1);
    for(int i=0; i<s.size()-n; i++) len[i] += 1;
    shuffle(len.begin(), len.end());
    
    vector<int> res;
    for(int i=0, x=0; i<n; i++){
        res.push_back(stoi(s.substr(x, len[i])));
        x += len[i];
    }
    return res;
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int L = opt<int>("len");
    string S;
    for(int i=0; i<L; i++) S += char('0' + rnd.next(1, 9));
    int N = rnd.next(max(1,(L+1)/2), min(9,L));
    auto A = Gen(N, S), B = Gen(N, S);
    
    cout << N << "\n";
    for(int i=0; i<N; i++) cout << A[i] << " \n"[i+1==N];
    for(int i=0; i<N; i++) cout << B[i] << " \n"[i+1==N];
    return 0;
}