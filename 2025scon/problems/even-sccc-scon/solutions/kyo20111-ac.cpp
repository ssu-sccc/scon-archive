#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int n;
ll dp[1001001][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp[1][0] = 24, dp[1][1] = 2;
    for(int i=2;i<=n;i++) {
        for(int j=0;j<2;j++) {
            dp[i][j] = (dp[i-1][j]*24 + dp[i-1][!j]*2) % mod;
        }
    }
    cout << dp[n][0];
}