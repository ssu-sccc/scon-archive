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

	ll A[n], B[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		if (!A[i]) {
			B[i] *= -1;
		}
	}
	for (int i = n - 1; i > 0; i--) B[i - 1] += B[i];

	ll ans = B[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (B[i] > 0) {
			ans += B[i];
			cnt += 1;
		}
	}
	cout << cnt << ' ' << ans << '\n';
}