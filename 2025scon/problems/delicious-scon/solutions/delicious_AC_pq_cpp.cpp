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

    for (int j = 1; j <= M; j++)
        dp[1][j] = arr[1][j];

    vector<priority_queue<pair<int, int>>> pqL(C), pqR(C);

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < C; j++) {
            pqL[j] = priority_queue<pair<int, int>>();
            pqR[j] = priority_queue<pair<int, int>>();
        }

        for (int j = 1; j <= M; j++) {
            int idx = j % C;
            pqL[idx].push({dp[i - 1][j], j});
            while (!pqL[idx].empty() && abs(j - pqL[idx].top().second) > D) {
                pqL[idx].pop();
            }
            if (!pqL[idx].empty()) {
                dp[i][j] = max(dp[i][j], pqL[idx].top().first + arr[i][j]);
            }
        }

        for (int j = M; j >= 1; j--) {
            int idx = j % C;
            pqR[idx].push({dp[i - 1][j], j});
            while (!pqR[idx].empty() && abs(j - pqR[idx].top().second) > D) {
                pqR[idx].pop();
            }
            if (!pqR[idx].empty()) {
                dp[i][j] = max(dp[i][j], pqR[idx].top().first + arr[i][j]);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= M; j++)
        ans = max(ans, dp[N][j]);
    cout << ans;
}
