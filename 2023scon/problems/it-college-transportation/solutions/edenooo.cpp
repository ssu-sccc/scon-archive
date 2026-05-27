#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N, A, B;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> A >> B;
	if (A < B) cout << "Bus\n";
	else if (A > B) cout << "Subway\n";
	else cout << "Anything\n";
	return 0;
}