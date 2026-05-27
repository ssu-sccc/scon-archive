#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, K, X;
bool can[15][15];
vector<pair<int, int> > v;

int res = -1;
vector<vector<int> > ans, w;
void f(int ord, int val)
{
	if (res < val) res = val, ans = w;
	if (ord == N) return;
	int i = v[ord].second;

	for(int k=0; k<K; k++)
		if (can[i][k] && w[k].size() < X)
		{
			w[k].push_back(i);
			f(ord+1, val+(1<<N-1-ord));
			w[k].pop_back();
		}
	f(ord+1, val);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> K >> X;
	for(int i=0; i<N; i++)
	{
		int x, y;
		cin >> x;
		while(x--)
		{
			cin >> y;
			y--; // 0-based
			can[i][y] = true;
		}
	}
	for(int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		v.push_back({x, i});
	}
	sort(v.rbegin(), v.rend());

	w.resize(K);
	f(0, 0);

	for(int i=0; i<K; i++)
	{
		cout << ans[i].size() << " ";
		for(int x : ans[i])
			cout << x+1 << " ";
		cout << "\n";
	}
	return 0;
}