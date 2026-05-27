#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, M;
vector<int> g[41];
bool vis[41];

void DFS(int n)
{
	vis[n] = true;
	for(int next : g[n])
		if (!vis[next])
			DFS(next);
}

int main()
{
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 0;
	for(int i=1; i<=N; i++)
		if (!vis[i])
			DFS(i), cnt++;
	cout << cnt-1 << "\n";
	return 0;
}