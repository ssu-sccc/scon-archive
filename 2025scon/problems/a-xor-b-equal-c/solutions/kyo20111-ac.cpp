#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int x, y;
ll dp[3030][3030];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> y;
    dp[x][y] = 1;
    for(int i=x;i>=0;i--) for(int j=y-(i==x);j>=0;j--) {
        dp[i][j] = (dp[i][j+3] + dp[i+2][j+1]*3) % mod;
    }
    cout << dp[0][0];
}