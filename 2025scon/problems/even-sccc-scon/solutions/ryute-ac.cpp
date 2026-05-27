#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll dp[1010101][2][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dp[1][0][0] = 24;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][1] = 0;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i][0][0] =
		    (dp[i - 1][0][0] * 24 + dp[i - 1][1][0] + dp[i - 1][0][1]) % MOD;
		dp[i][0][1] =
		    (dp[i - 1][0][1] * 24 + dp[i - 1][0][0] + dp[i - 1][1][1]) % MOD;
		dp[i][1][0] =
		    (dp[i - 1][1][0] * 24 + dp[i - 1][0][0] + dp[i - 1][1][1]) % MOD;
		dp[i][1][1] =
		    (dp[i - 1][1][1] * 24 + dp[i - 1][1][0] + dp[i - 1][0][1]) % MOD;
	}
	cout << (dp[n][0][0] + dp[n][1][1]) % MOD;

	return 0;
}