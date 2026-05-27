#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<string> res;
	vector<pair<int, char> > ans;
	for(int i=0; i<3; i++)
	{
		int p, y;
		string s;
		cin >> p >> y >> s;
		res.push_back(to_string(y%100));
		ans.push_back({p, s[0]});
	}
	sort(res.begin(), res.end());
	sort(ans.rbegin(), ans.rend());

	for(auto s : res)
		cout << s;
	cout << "\n";

	for(auto [x,c] : ans)
		cout << c;
	cout << "\n";
	return 0;
}