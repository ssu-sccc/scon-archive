#include <bits/stdc++.h>
using namespace std;

int F[5050][5050], A[5050], B[5050];

void Init(int n=5000){
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n; j++) F[i][j] = F[i-1][j];
        int x = i;
        for(int p=2; x>1; p++) while(x % p == 0) F[i][p]++, x /= p;
    }
}

void Go(int n, int r, int *cnt){
    for(int i=1; i<=n; i++) cnt[i] += F[n][i];
    for(int i=1; i<=r; i++) cnt[i] -= F[r][i];
    for(int i=1; i<=n-r; i++) cnt[i] -= F[n-r][i];
}

void Solve(){
    int n1, r1, n2, r2;
    cin >> n1 >> r1 >> n2 >> r2;
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    Go(n1, r1, A); Go(n2, r2, B);
    bool flag = true;
    for(int i=1; i<=5000; i++) flag &= A[i] == 0 || B[i] == 0;
    cout << flag << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC; Init();
    for(int tc=1; tc<=TC; tc++) Solve();
}