#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
 
int main(int argc, char* argv[])
{
	registerValidation(argc, argv);
	int N = inf.readInt(1, 80, "N"); inf.readEoln();
	string s = inf.readToken("[a-z]+", "s"); inf.readEoln();
	inf.readEof();

	ensuref((int)s.size() == N, "|s| == N");
	for(int i=0; i+2<N; i++)
		ensuref(s.substr(i, 3) != "int", "input cannot contain substring int");
	return 0;
}