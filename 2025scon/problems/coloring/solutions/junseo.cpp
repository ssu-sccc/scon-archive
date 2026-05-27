#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)v.size()
#define rmin(r, x) r = min(r, x)
#define rmax(r, x) r = max(r, x)
#define ends ' '
#define endl '\n'
#define rep(i, s, e) for(int i = (s); i <= (e); ++i)
#define rep2(i, e, s) for(int i = (e); i >= (s); --i)
#define print(v) copy(all(v), ostream_iterator<int>(cout, " ")), cout << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;

// #define LOCAL

const int maxn = 2e5 + 10;

int N, color[maxn];
vector<int> adj[maxn];

void dfs(int u, int col) {
	color[u] = col;
	for(auto& v : adj[u]) if(color[v] == 0) {
		dfs(v, (col == 1 ? 2 : 1));
	}
}

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> N;
	rep(i, 1, N) {
		int u, v;	cin >> u >> v;
		adj[u].eb(v);
		adj[v].eb(u);
	}

	dfs(1, 1);

	rep(u, 1, N) for(auto& v : adj[u]) {
		if(color[u] == color[v]) {
			cout << 3;
			return 0;
		}
	}
	cout << 2;
	return 0;
}
