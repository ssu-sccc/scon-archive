#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;
const int MOD = 1e9+7;

int half[50505];
ll dp[50505][1024];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int m = M >> 1;
    for (int i = 1; i <= N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < m; j++) {
            half[i] <<= 1;
            half[i] |= (S[j] == S[M - 1 - j] ? 0 : 1);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (1 << m); j++)
            dp[i][j] = dp[i - 1][j];
        dp[i][half[i]] = (dp[i][half[i]] + 1) % MOD;
        for (int j = 0; j < (1 << m); j++)
            dp[i][j ^ half[i]] = (dp[i][j ^ half[i]] + dp[i - 1][j]) % MOD;
    }
    cout << dp[N][0];
}