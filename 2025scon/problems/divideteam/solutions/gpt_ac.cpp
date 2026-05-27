#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int64> B(N);
    for(int i = 0; i < N; i++) cin >> B[i];

    // C_i 정의
    vector<int64> C(N);
    for(int i = 0; i < N; i++){
        C[i] = (A[i] == 1 ?  B[i] : -B[i]);
    }

    // suffix sums
    vector<int64> suf(N+1, 0);
    for(int i = N-1; i >= 0; i--){
        suf[i] = suf[i+1] + C[i];
    }

    // 기본 S = suf[0], M = 1
    int64 S = suf[0];
    int cuts = 0;
    // i from 1 to N-1 corresponds to suf[i]
    for(int i = 1; i < N; i++){
        if(suf[i] > 0){
            S += suf[i];
            cuts++;
        }
    }

    int M = cuts + 1;
    cout << M << " " << S << "\n";
    return 0;
}
