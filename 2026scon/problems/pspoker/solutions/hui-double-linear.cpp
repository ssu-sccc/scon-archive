#include <bits/stdc++.h>
using namespace std;

int N, A[202020], B[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];

    double mx = 0;
    for(int i=1; i<=N; i++) mx = max(mx, 1. * B[i] / A[i]);
    for(int i=N; i>=1; i--) if(1. * B[i] / A[i] == mx) { cout << i << "\n"; return 0; }
}