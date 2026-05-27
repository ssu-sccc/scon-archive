#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

int N;
int A[500001], P[500001], res[500001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		cin >> A[i];
		P[A[i]] = i;
	}
	for(int i=1; i<=N; i++)
		if (A[i] != i)
		{
			int x = A[i], y = i; // 값 x와 y의 위치를 swap한다.
			res[x] += abs(P[x] - P[y]);
			res[y] += abs(P[x] - P[y]);
			swap(P[x], P[y]);
			A[P[x]] = x;
			A[P[y]] = y;
		}
	for(int x=1; x<=N; x++)
		cout << res[x] << " ";
	cout << "\n";
	return 0;
}