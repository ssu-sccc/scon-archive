#include<bits/stdc++.h>
using namespace std;

int N;
string s;

int f(int i)
{
	if (i >= s.size()) return 1;
	int ret = f(i+1);
	if (s.substr(i, 8) == "longlong") ret += f(i+8);
	return ret;
}

int main()
{
	cin >> N >> s;
	cout << f(0) << "\n";
	return 0;
}