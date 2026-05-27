#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, M, S;
int p[2020];

int Find(int n)
{
	if (n == p[n]) return n;
	return Find(p[n]); // slow find
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	if (a == b) return;
	p[a] = b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> M >> S;
	for(int i=1; i<=N; i++)
		p[i] = i;

	vector<array<int, 3> > e;
	for(int i=0; i<M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({c, a, b});
	}
	// ignore input A[]
	sort(e.begin(), e.end());

	int res = 0;
	for(auto [c,a,b] : e)
	{
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		res += c;
	}
	cout << res << "\n";
	return 0;
}