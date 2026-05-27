#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
int n;
ll a[1010101];
ll b[1010101];
int cut[1010101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	ll sa = 0, sb = 0, diff = 0, ar = 0;
	for (int i = n; i >= 2; i--) {
		if (a[i] == 0) sa += b[i];
		else sb += b[i];

		if (sb > sa) cut[i] = 1, ar++;
	}

	ll ca = 0, cb = 0, round = 1;
	for (int i = 1; i <= n; i++) {
		if (cut[i]) round++;
		if (a[i] == 0) ca += round * b[i];
		else cb += round * b[i];
	}
	cout << ar + 1 << ' ' << cb - ca << endl;
	return 0;
}