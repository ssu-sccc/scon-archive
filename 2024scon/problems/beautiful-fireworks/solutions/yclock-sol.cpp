#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200'005;

vector<int> G[MAXN];

ll S[MAXN];
int D[MAXN];

ll A[MAXN];

ll Ans, W;
int N;

void dfs1(int i, int p) {
	S[i] = A[i];

	for(int v : G[i]) if(v != p) {
		D[v] = D[i] + 1;
		dfs1(v, i);
		S[i] += S[v];
	}
}

void dfs2(int i, int p, ll x) {
	Ans = max(Ans, x);

	for(int v : G[i]) if(v != p) {
		dfs2(v, i, x + S[1] - S[v] * 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for(int t = N-1; t--;) {
		int a, b;
		cin >> a >> b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	for(int i = 1; i <= N; i++) cin >> A[i];

	dfs1(1, 0);

	for(int i = 2; i <= N; i++)
		W += A[i] * D[i];

	dfs2(1, 0, 0);

	cout << Ans + W << '\n';

	return 0;
}