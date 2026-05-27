#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 5050;

int not_prime[SZ];
int C[SZ][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	not_prime[0] = not_prime[1] = true;
	for (int n = 2; n < SZ; n++) {
		if (not_prime[n]) continue;
		for (int x = 2 * n; x < SZ; x += n) {
			not_prime[x] = true;
		}
	}

	for (int p = 0; p < SZ; p++) {
		if (not_prime[p]) continue;
		for (int n = 1; n < SZ; n++) {

			int c = 0, x = n;
			while (x % p == 0) {
				c += 1;
				x /= p;
			}
			C[n][p] = C[n - 1][p] + c;
		}
	}

	int TC;
	cin >> TC;
	while (TC--) {
		int n1, k1, n2, k2;
		cin >> n1 >> k1 >> n2 >> k2;

		bool coprime = true;
		for (int p = 0; p <= max(n1, n2); p++) {
			if (not_prime[p]) continue;
			int c1 = C[n1][p] - C[k1][p] - C[n1 - k1][p];
			int c2 = C[n2][p] - C[k2][p] - C[n2 - k2][p];
			
			if (c1 > 0 && c2 > 0) {
				coprime = false;
				break;
			}
		}
		cout << (coprime ? "1\n" : "0\n");
	}
}