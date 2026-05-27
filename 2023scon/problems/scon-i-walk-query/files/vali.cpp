#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char *argv[])
{
	registerValidation(argc, argv);
	int N = inf.readInt(2, 300'000, "N"); inf.readSpace();
	int Q = inf.readInt(1, 600'000, "Q"); inf.readEoln();

	set<pair<int, int> > e;
	for(int i=0; i<Q; i++)
	{
		int a = inf.readInt(1, N-1, "a"); inf.readSpace();
		int b = inf.readInt(a+1, N, "b"); inf.readEoln();
		ensuref(e.find({a, b}) == e.end(), "input must be a simple graph");
		e.insert({a, b});
	}
	inf.readEof();
	return 0;
}