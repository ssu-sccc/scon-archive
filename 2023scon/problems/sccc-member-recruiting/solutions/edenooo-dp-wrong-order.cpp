#include<bits/stdc++.h>
using namespace std;
 
#define INF 1234567890
#define ll long long
 
int N, K, X;
bool can[15][15];
vector<pair<int, int> > v;
int pw[15+1];
int dp[15+1][1<<15];

vector<int> res[15];
void f(int i, int j) // 역추적
{
	if (i == N) return;
	if (dp[i][j] == dp[i+1][j])
	{
		f(i+1, j);
		return;
	}
	for(int k=0; k<K; k++)
		if (can[i][k] && j/pw[k]%(X+1) < X)
			if (dp[i][j] == dp[i+1][j+pw[k]] + (1<<N-1-i))
			{
				res[k].push_back(i);
				f(i+1, j+pw[k]);
				return;
			}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> K >> X;
	pw[0] = 1;
	for(int k=1; k<=K; k++)
		pw[k] = pw[k-1] * (X+1);
 
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
 
	for(int i=N-1; i>=0; i--)
		for(int j=0; j<pw[K]; j++)
		{
			// dp[i][j] : i번째를 고를 차례인데 현재 bit의 상태가 j일 때, 이후 추가로 얻을 수 있는 점수의 최댓값
			dp[i][j] = dp[i+1][j];
			for(int k=0; k<K; k++)
				if (can[i][k] && j/pw[k]%(X+1) < X)
					dp[i][j] = max(dp[i][j], dp[i+1][j+pw[k]] + (1<<N-1-i));
		}
	f(0, 0);
	for(int k=0; k<K; k++)
	{
		cout << res[k].size() << " ";
		for(int i : res[k])
			cout << i+1 << " ";
		cout << "\n";
	}
	return 0;
}
