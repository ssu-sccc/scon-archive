#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define MOD 1000000007

using ll=long long;

ll dp[2][1000100];

int main(void){
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N; dp[0][0] = 1;
    for(int i = 1; i <= N; i++){
        dp[0][i] = (dp[0][i-1]*24 + dp[1][i-1]*2)%MOD;
        dp[1][i] = (dp[1][i-1]*24 + dp[0][i-1]*2)%MOD;
    }
    cout << (dp[0][N])%MOD << "\n";
}    
