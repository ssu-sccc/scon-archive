#include<bits/stdc++.h>
using namespace std;

int N, F[21];
string s;

int main()
{
	F[0] = F[1] = 1;
	for(int i=2; i<=20; i++)
		F[i] = F[i-1] + F[i-2];
	cin >> N >> s;
	int res = 1;
	for(int i=0; i<s.size(); i++)
	{
		int cnt = 0;
		while (s.substr(i, 4) == "long") cnt++, i += 4;
		res *= F[cnt];
	}
	cout << res << "\n";
	return 0;
}