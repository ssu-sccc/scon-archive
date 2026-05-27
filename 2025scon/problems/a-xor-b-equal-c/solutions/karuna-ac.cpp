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
mint mpow(mint a, ll x) {
	mint r = 1;
	while (x) {
		if (x & 1) r *= a;
		a *= a;
		x /= 2;
	}
	return r;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	if (x & 1) return !(cout << "0\n");

	int n = (x + y) / 3;
	x /= 2;

	mint ans = mpow(3, x);
	mint b = 1;
	for (int a = 1; a <= x; a++) b *= a;
	b = mpow(b, MOD - 2);
	for (int a = n; a > n - x; a--) b *= a;
	cout << ans * b << '\n';
}