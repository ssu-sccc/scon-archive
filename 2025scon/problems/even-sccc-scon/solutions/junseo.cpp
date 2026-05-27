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

const ll mod = 1e9 + 7;

const int maxn = 1e6 + 10;

ll N;
ll p2[maxn], p24[maxn], fac[maxn], inv[maxn];

ll mypow(ll a, ll b) {
	ll r = 1, x = a;
	while(b) {
		if(b & 1)	r = r * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return r;
}

ll C(ll a, ll b) {
	return fac[a] * inv[b] % mod * inv[a-b] % mod;
}

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> N;
	p2[0] = p24[0] = fac[0] = 1;
	rep(i, 1, N) {
		p2[i] = p2[i-1]*2 % mod;
		p24[i] = p24[i-1]*24 % mod;
		fac[i] = fac[i-1]*i % mod;
	}
	inv[N] = mypow(fac[N], mod-2);
	rep2(i, N-1, 0)	inv[i] = inv[i+1]*(i+1)%mod;

	ll ans = 0;
	for(ll x = 0; x <= N; x += 2) {
		// 2^x * 24^(N-x) * C(N, x)
		ll t = p2[x] * p24[N-x] % mod;
		ans = (ans + t*C(N, x)%mod) % mod;
	}
	cout << ans;
	return 0;
}
