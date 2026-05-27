#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SZ = 100;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;

	int C[SZ]{};
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		C[a - 1] += 1;
		C[b - 1] += 1;
		C[c - 1] += 1;
	}
	auto calc = [&]() {
		for (int i = SZ - 1; i >= 0; i--) {
			if (C[i] == 1) {
				return i;
			}
		}
		return -1;
	};

	int ans = 0;
	for (int a = 0; a < SZ; a++) for (int b = 0; b < a; b++) for (int c = 0; c < b; c++) {
		C[a] += 1;
		C[b] += 1;
		C[c] += 1;
		int r = calc();
		if (a == r || b == r || c == r) {
			ans += 1;
		}
		C[a] -= 1;
		C[b] -= 1;
		C[c] -= 1;
	}
	cout << ans << '\n';
}