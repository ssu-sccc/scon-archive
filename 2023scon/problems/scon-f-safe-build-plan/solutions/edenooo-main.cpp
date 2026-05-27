#include<bits/stdc++.h>
using namespace std;

int N, M, res;
int g[41][41];

bool Try(int cost)
{
	for(int i=1; i<=N; i++)
		for(int j=i+1; j<=N; j++)
			for(int k=j+1; k<=N; k++)
				if (g[i][j] + g[j][k] + g[i][k] == 2-cost)
				{
					g[i][j] = g[j][k] = g[i][k] = 1;
					res += cost;
					return true;
				}
	return false;
}

int main()
{
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
	}
	while(Try(0) || Try(1));
	cout << res << "\n";
	return 0;
}