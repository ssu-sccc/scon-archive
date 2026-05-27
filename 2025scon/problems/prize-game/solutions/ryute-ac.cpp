#include <bits/stdc++.h>

using namespace std;

int a[105];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, ans = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1]++;
		a[t2]++;
		a[t3]++;
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			for (int k = j + 1; k <= 100; k++) {
				int flag = 0;
				for (int th = 100; th >= 1; th--) {
					if (a[th] == 0 && (i == th || j == th || k == th)) {
						flag = 1;
						break;
					}
					if (a[th] == 1 && (i != th && j != th && k != th)) {
						break;
					}
				}
				ans += flag;
			}
		}
	}
	cout << ans;
	return 0;
}