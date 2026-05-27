#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	--m;

	int T[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		T[x - 1] = i;
	}

	ll cw = 0, ccw = 0;
	for (int i = 0; i < m; i++) {
		cw = (cw - T[i] + n - 1) / n * n + T[i];
	}
	for (int i = n - 1; i >= m; i--) {
		ccw = (ccw - T[i] + n - 1) / n * n + T[i];
	}

	if (cw == ccw) {
		assert(false);
		cout << "EQ\n";
	}
	else {
		cout << (cw < ccw ? "CW\n" : "CCW\n");
	}
}