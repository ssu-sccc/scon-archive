#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 25252;

int dp[2][SZ];
void chmax(int &x, int v) {
	x = max(x, v);
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m, c, d;
	cin >> n >> m >> c >> d;
	
	int B[n];
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		--B[i];
	}
	int f = 0;
	for (int i = 0; i < m; i++) dp[f][i] = m - abs(i - B[0]);

	for (int i = 1; i < n; i++) {
		f ^= 1;
		for (int j = 0; j < m; j++) dp[f][j] = 0;

		for (int r = 0; r < c; r++) {
			deque<int> dq;
			int p = r;
			for (int j = r; j < m; j += c) {
				while (!dq.empty() && dq.front() < j - d) dq.pop_front();
				while (p < min(m, j + d + 1)) {
					while (!dq.empty() && dp[f ^ 1][dq.back()] <= dp[f ^ 1][p]) {
						dq.pop_back();
					}
					dq.push_back(p);
					p += c;
				}
				assert(!dq.empty());
				dp[f][j] = dp[f ^ 1][dq.front()] + m - abs(j - B[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans = max(ans, dp[f][i]);
	}
	cout << ans << '\n';
}