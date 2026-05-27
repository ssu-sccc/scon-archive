#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;

int bin[50505];
ll dp[2][2020202];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int m = 1 << M;
    for (int i = 1; i <= N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < M; j++) {
            bin[i] <<= 1;
            bin[i] |= S[j] == '1' ? 1 : 0;
        }
    }
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        int next = cur ^ 1;
        for (int j = 0; j < m; j++)
            dp[next][j] = dp[cur][j];
        dp[next][bin[i]] = (dp[next][bin[i]] + 1) % MOD;
        for (int j = 0; j < m; j++)
            dp[next][j ^ bin[i]] = (dp[next][j ^ bin[i]] + dp[cur][j]) % MOD;
        cur = next;
    }
    ll ans = 0;
    for (int mask = 0; mask < m; mask++) {
        bool pal = 1;
        for (int j = 0; j < M; j++)
            if (((mask >> j) & 1) != ((mask >> (M - j - 1)) & 1)) {
                pal = 0;
                break;
            }
        if (pal)
            ans = (ans + dp[cur][mask]) % MOD;
    }
    cout << ans;
}