#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define INF 1234567890
#define ll long long

int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int N = inf.readInt(3, 40, "N"); inf.readSpace();
	int M = inf.readInt(1, N*(N-1)/2, "M"); inf.readEoln();

	vector<vector<int> > g(41, vector<int>(41, 0));
	for(int i=0; i<M; i++)
	{
		int a = inf.readInt(1, N-1, "a"); inf.readSpace();
		int b = inf.readInt(a+1, N, "b"); inf.readEoln();
		ensuref(g[a][b] == 0, "input must be a simple graph");
		g[a][b] = 1;
	}
	inf.readEof();
	return 0;
}