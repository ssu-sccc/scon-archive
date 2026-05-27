#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, c, d;
ll b[202];
int mod = 0;
ll ans = 0;

void solve() {
	vector<ll> dp[2];
	int togg = 0;
	int sz = m / c + 3;
	dp[0].resize(sz);
	dp[1].resize(sz);

	for (int i = 0; i * c + mod <= m; i++)
		dp[0][i] = m - abs(i * c + mod - b[0]);

	for (int i = 1; i < n; i++) {
		togg = 1 - togg;
		deque<pair<ll, ll>> Q;
		int last = 0;
		for (int j = 0; j < sz; j++) {
			int temp = mod + j * c;
			if (temp > m) break;
			// calculate dp[togg][j]

			while (!Q.empty() && Q.front().first < j - (d / c)) Q.pop_front();
			while (mod + last * c <= m && last <= j + (d / c)) {
				while (!Q.empty() && Q.back().second <= dp[1 - togg][last])
					Q.pop_back();
				Q.push_back(make_pair(last, dp[1 - togg][last]));
				last++;
			}

			dp[togg][j] = Q.front().second + m - abs(j * c + mod - b[i]);
		}
	}

	for (int i = 0; i * c + mod <= m; i++) ans = max(ans, dp[togg][i]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> c >> d;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 1; i <= c; i++) {
		mod = i;
		solve();
	}
	cout << ans;

	return 0;
}