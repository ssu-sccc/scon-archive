#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N;
string s;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> s;
	int res = 1;
	for(int i=0; i<s.size(); i++)
	{
		int a = 1, b = 1;
		while (i+3 < s.size() && s[i] == 'l' && s[i+1] == 'o' && s[i+2] == 'n' && s[i+3] == 'g') tie(a,b) = make_pair(b, a+b), i += 4;
		res *= a;
	}
	cout << res << "\n";
	return 0;
}