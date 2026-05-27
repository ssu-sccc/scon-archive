#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, Q;
vector<int> g[300001];
int vis[300001], col[300001];

int die, cnt;
void DFS(int n, int c, int t)
{
	vis[n] = t; col[n] = c; cnt++;
	for(int next : g[n])
	{
		if (vis[next] == t)
		{
			if (col[next] == c) die = 1;
			continue;
		}
		DFS(next, c^1, t);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> Q;
	for(int t=1; t<=Q; t++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);

		int res = 0;
		for(int i=1; i<=N; i++)
			if (vis[i] != t)
			{
				die = 0; cnt = 0;
				DFS(i, 0, t);
				if (die) res += cnt;
			}
		cout << res << "\n";
	}
	return 0;
}