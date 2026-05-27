#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll dp[3030][3030];
ll ncr(ll n, ll r) {
	if (n == r || r == 0) return 1;
	if (dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x, y, s;
	cin >> x >> y;
	s = (x + y) / 3;
	if (x % 2 != 0) {
		cout << 0;
		return 0;
	}

	x /= 2;
	if (x > s) {
		cout << 0;
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	ll ans = ncr(s, x);
	for (int i = 0; i < x; i++) ans = (ans * 3) % MOD;
	cout << ans;

	return 0;
}