#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, M, A[101010], R;

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) A[i] = max(0ll, A[i-1] + A[i]);
    for(int i=1; i<=N; i++) R += A[i] >= M;
    cout << R;
}