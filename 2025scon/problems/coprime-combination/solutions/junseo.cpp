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

const int maxk = 5e3 + 10;

int idxs[maxk];
vector<int> primes;
vector<pii> factors[maxk];

void pre() {
	int idx = 0;
	rep(i, 2, maxk-1) {
		int x = i;
		for(int j = 2; j * j <= x; ++j) {
			int cnt = 0;
			while(x % j == 0) {
				x /= j;
				cnt += 1;
			}
			if(cnt >= 1)	factors[i].eb(j, cnt);
		}
		if(x > 1)	factors[i].eb(x, 1);

		if(factors[i].size() == 1) {
			idxs[i] = idx++;
			primes.eb(i);
		}
	}
}

vector<int> calc(int n, int r) {
	vector<int> ret(primes.size());

	rep2(x, n, n-r+1) {
		for(auto& [p, c] : factors[x]) {
			ret[idxs[p]] += c;
		}
	}
	rep(x, 2, r) {
		for(auto& [p, c] : factors[x]) {
			ret[idxs[p]] -= c;
		}
	}

	return ret;
}

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	// |primes of [1..5000]| = 669
	// 2*3*5*7*11 = 2310 <= 5000
	pre();

	int TC;	cin >> TC;
	while(TC--) {
		// C(n, r)
		// = n*(n-1)*...*(n-r+1) / r!

		int n1, r1, n2, r2;
		cin >> n1 >> r1 >> n2 >> r2;

		auto p1 = calc(n1, r1);
		auto p2 = calc(n2, r2);

		bool cop = true;
		rep(i, 0, p1.size()-1) {
			if(!p1[i] || !p2[i])	continue;
			cop = false;
			break;
		}
		cout << (cop ? 1 : 0) << endl;
	}
	return 0;
}
