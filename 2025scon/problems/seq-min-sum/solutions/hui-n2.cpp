#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;

int N;
alignas(32) int A[500'000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++) A[i] = min(A[i], A[j]);
    }
    cout << accumulate(A, A+N, 0LL);
}