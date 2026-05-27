#include <bits/stdc++.h>

using namespace std;

long long a[505050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	long long ans = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (a[i + 1] < a[i]) a[i] = a[i + 1];
		ans += a[i];
	}
	cout << ans;
	return 0;
}