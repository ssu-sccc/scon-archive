#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[500500];
ll s[500500], dp[500500][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];

    for(int i=1;i<=n;i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][1] + a[i];
        if(i >= k) dp[i][1] = max(dp[i][1], dp[i-k][0] + s[i]-s[i-k]);
    }

    auto ans = max(dp[n][0], dp[n][1]);
    for(int i=1;i<k;i++) ans = max(ans, dp[n-i][0] + s[n]-s[n-i]);
    cout << ans;
}