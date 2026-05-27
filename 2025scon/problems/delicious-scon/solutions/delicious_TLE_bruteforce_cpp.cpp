#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, C, D;
    cin >> N >> M >> C >> D;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= M; j++)
            arr[i][j] = M - abs(j - k);
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            for (int k = j; k <= min(M, j + D); k += C)
                dp[i][j] = max(dp[i][j], dp[i - 1][k]);
            for (int k = j; k >= max(1, j - D); k -= C)
                dp[i][j] = max(dp[i][j], dp[i - 1][k]);
            dp[i][j] += arr[i][j];
        }
    int ans = 0;
    for (int j = 1; j <= M; j++)
        ans = max(ans, dp[N][j]);
    cout << ans;
}
