#include<bits/stdc++.h>
using namespace std;
 
#define INF 1234567890
#define ll long long
 
int N, Q, res;
vector<int> g[300001];
int vis[300001], col[300001], odd[300001];

void Fill(int n)
{
	odd[n] = true; res++;
	for(int next : g[n])
		if (!odd[next])
			Fill(next);
}
 
bool DFS(int n, int c, int t) // 이번에 홀수 사이클이 생겼는가?
{
	vis[n] = t; col[n] = c;
	for(int next : g[n])
	{
		if (vis[next] == t)
		{
			if (col[next] == c) return true;
			continue;
		}
		if (DFS(next, c^1, t)) return true;
	}
	return false;
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

		if (odd[a] && !odd[b]) Fill(b);
		if (odd[b] && !odd[a]) Fill(a);
		g[a].push_back(b);
		g[b].push_back(a);
		if (!odd[a] && !odd[b] && DFS(a, 0, t)) Fill(a);
		
		cout << res << "\n";
	}
	return 0;
}
