#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int L, int R) { return uniform_int_distribution<int>(L, R)(rng); } // closed

int N = 300000, Q = 600000, cnt = 300000;
int C[300001], p[300001];

int Find(int n)
{
	if (n == p[n]) return n;
	return p[n] = Find(p[n]);
}

void Union(int a, int b)
{
	a = Find(a); b = Find(b);
	if (a == b) return;
	p[a] = b;
	cnt--;
}

int main()
{
	ofstream cout("out.txt");
	cout << N << " " << Q << "\n";

	for(int i=1; i<=N; i++)
	{
		C[i] = Rand(0, 1);
		p[i] = i;
	}

	set<pair<int, int> > e;
	while(Q >= 100000 && cnt >= 10000) // 이분 그래프 유지하기
	{
		while(1)
		{
			int a = Rand(1, N-1);
			int b = Rand(a+1, N);
			if (C[a] == C[b] || e.find({a, b}) != e.end()) continue;
			e.insert({a, b});
			Union(a, b);
			cout << a << " " << b << "\n";
			break;
		}
		Q--;
	}
	cerr << Q << " " << cnt << "\n";
	while(Q--) // 아무 간선이나 만들기
	{
		while(1)
		{
			int a = Rand(1, N-1);
			int b = Rand(a+1, N);
			if (e.find({a, b}) != e.end()) continue;
			e.insert({a, b});
			Union(a, b);
			cout << a << " " << b << "\n";
			break;
		}
	}
	cout.flush();
	cerr << cnt << "\n";
	return 0;
}