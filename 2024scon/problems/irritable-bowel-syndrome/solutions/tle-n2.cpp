#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;

alignas(32) int N, M, A[100'000], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=0; j<=i; j++) sum = max(0, sum + A[j]);
        R += sum >= M;
    }
    cout << R;
}