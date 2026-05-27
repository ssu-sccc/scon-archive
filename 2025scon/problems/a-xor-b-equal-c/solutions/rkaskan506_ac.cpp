#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define MOD 1000000007

using ll=long long;

int dp[3030][3030];

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    
    if(N%2){
        cout << "0\n";
        return 0;
    }

    if((M-N/2)%3){
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;
    for(int i = 1; i <= 3000; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= MOD;
        }
    }

    ll res = dp[(N+M)/3][N/2];
    for(;N;N-=2) res=(res*3)%MOD;
    cout << res << "\n";
}    
