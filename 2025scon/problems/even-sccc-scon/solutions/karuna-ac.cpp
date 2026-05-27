#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
struct mint {
	int x;
	mint() : x(0) {}
	mint(int x) : x(x) {}
	mint operator+(int ot) const { return x + ot >= MOD ? x - MOD + ot : x + ot; }
	mint operator-(int ot) const { return x < ot ? x - ot + MOD : x - ot; }
	mint operator*(int ot) const { return 1ll * x * ot % MOD; }
	mint operator+=(int ot) { return *this = *this + ot; }
	mint operator-=(int ot) { return *this = *this - ot; }
	mint operator*=(int ot) { return *this = *this * ot; }
	operator int() { return x; }
};

const int SZ = 1010101;
mint dp[2][SZ];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] * 24 + dp[1][i - 1] * 2;
		dp[1][i] = dp[1][i - 1] * 24 + dp[0][i - 1] * 2;
	}
	cout << dp[0][n] << '\n';
}