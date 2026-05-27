#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int vis[202020], flag = 0;
vector<int> adj[202020];

void dfs(int x, int c) {
	vis[x] = c;
	for (int th : adj[x]) {
		if (vis[th] == c) flag = 1;
		if (vis[th]) continue;
		dfs(th, 3 - c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	dfs(1, 1);
	cout << 2 + flag;

	return 0;
}