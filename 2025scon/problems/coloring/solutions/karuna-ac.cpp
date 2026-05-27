#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 202020;

int dep[SZ];
vector<int> gph[SZ];
void dfs(int p, int v) {
	for (int x : gph[v]) if (p != x) {
		if (dep[x] == -1) {
			dep[x] = dep[v] + 1;
			dfs(v, x);
		}
		else if (dep[x] < dep[v]) {
			cout << 3 - ((dep[v] - dep[x]) & 1) << '\n';
			exit(0);
		}
	}
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		gph[u].push_back(v);
		gph[v].push_back(u);
	}
	fill(dep, dep + n, -1);
	dfs(-1, 0);
}