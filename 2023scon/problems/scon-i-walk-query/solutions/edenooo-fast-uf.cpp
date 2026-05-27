#include<bits/stdc++.h>
using namespace std;
 
int N, Q, res;
int p[600001], sz[600001], rnk[600001];

int Not(int n)
{
	if (n <= N) return n+N;
	return n-N;
}
 
int Find(int n)
{
	if (n == p[n]) return n;
	return p[n] = Find(p[n]);
}
 
void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	if (a == b) return;
 
	if (a == Find(Not(a))) res -= sz[a];
	if (b == Find(Not(b))) res -= sz[b];

	if (rnk[a] < rnk[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	if (rnk[a] == rnk[b]) rnk[a]++;

	if (a == Find(Not(a))) res += sz[a];
}
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for(int i=1; i<=N+N; i++)
		p[i] = i, sz[i] = (i <= N);
 
	while(Q--)
	{
		int a, b;
		cin >> a >> b;
		Union(a, Not(b));
		Union(b, Not(a));
		cout << res << "\n";
	}
	return 0;
}