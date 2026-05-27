#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define ep emplace
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)v.size()
#define rmin(r, x) r = min(r, x)
#define rmax(r, x) r = max(r, x)
#define ends ' '
#define endl '\n'
#define rep(i, s, e) for(int i = (s); i <= (e); ++i)
#define rep2(i, e, s) for(int i = (e); i >= (s); --i)
#define print(v) copy(all(v), ostream_iterator<int>(cout, " ")), cout << endl
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;

// #define LOCAL

const int mod = 1e9 + 7;
const int maxk = 3e3 + 10;

int X, Y;
ll D[maxk][maxk];

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> Y >> X;

	// 0 0 -> 0
	// 0 1 -> 1
	// 1 0 -> 1
	// 1 1 -> 0

	// (3, 0) or (1, 2)*3

	D[X][Y] = 1;
	auto add = [&](ll& r, ll d) {
		r += d;
		if(r >= mod)	r %= mod;
	};
	rep2(i, X, 0) rep2(j, Y, 0) {
		if(i >= 3)	add(D[i-3][j], D[i][j]);
		if(i >= 1 and j >= 2)	add(D[i-1][j-2], D[i][j]*3);
	}

	cout << D[0][0];
	return 0;
}
