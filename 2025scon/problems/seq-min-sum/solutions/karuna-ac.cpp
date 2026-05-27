#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;

	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = n - 1; i > 0; i--) A[i - 1] = min(A[i - 1], A[i]);

	cout << accumulate(A, A + n, 0ll) << '\n';
}