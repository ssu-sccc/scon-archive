#include <bits/stdc++.h>

using namespace std;

int n, m;
int mod[101010];  // t -> t + 1

long long tm, cw, ccw;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		mod[t] = i % n;
	}

	for (int i = 1; i < m; i++) { cw += (mod[i] + n - (cw % n)) % n; }
	for (int i = n; i >= m; i--) { ccw += (mod[i] + n - (ccw % n)) % n; }
	if (cw < ccw) cout << "CW" << endl;
	else if (ccw < cw) cout << "CCW" << endl;
	else cout << "EQ" << endl;

	return 0;
}