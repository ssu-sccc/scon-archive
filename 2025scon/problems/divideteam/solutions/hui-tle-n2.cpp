#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[1010101], B[1010101], C[1010101];
ll D[5050][5050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    for(int i=1; i<=N; i++) C[i] = A[i] ? B[i] : -B[i];
    partial_sum(C+1, C+N+1, C+1);

    memset(D, 0xc0, sizeof D); D[0][0] = 0;
    for(int i=1; i<=N; i++){
        ll mx = D[i-1][0];
        for(int j=1; j<=N; j++){
            D[i][j] = mx + C[j] * i;
            mx = max(mx, D[i-1][j] - C[j] * i);
        }
    }

    ll mx = -1e18, cnt = 0;
    for(int i=1; i<=N; i++) if(mx < D[i][N] || mx == D[i][N] && cnt > i) mx = D[i][N], cnt = i;
    cout << cnt << " " << mx;
}