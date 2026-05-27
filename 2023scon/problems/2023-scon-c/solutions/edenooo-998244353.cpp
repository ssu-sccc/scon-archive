#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N;
int A[100101];

int main()
{
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> A[i];

	for(int i=3; i<=N; i++)
		if (A[i-1]-A[i-2] != A[i]-A[i-1])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for(int i=1; i<=N; i++)
		cout << 998244353LL*A[i] << " ";
	cout << "\n";
	for(int i=1; i<=N; i++)
		cout << -998244352LL*A[i] << " ";
	cout << "\n";
	return 0;
}