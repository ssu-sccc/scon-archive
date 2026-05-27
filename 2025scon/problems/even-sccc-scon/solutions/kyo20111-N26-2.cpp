#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9+7;

int n, dp[1001001][26][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<26;i++) dp[1][i][i<2] = 1;
    for(int i=2;i<=n;i++) {
        for(int j=0;j<26;j++) {
            for(int k=0;k<26;k++) {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][k][j<2]) % mod;
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][k][!(j<2)]) % mod;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<26;i++) ans = (ans + dp[n][i][0]) % mod;
    cout << ans;
}