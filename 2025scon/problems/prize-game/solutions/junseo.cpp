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

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	int N;	cin >> N;
	vector<int> cnt(100+1, 0);

	rep(i, 1, N) {
		rep(_, 1, 3) {
			int x;	cin >> x;
			cnt[x] += 1;
		}
	}

	int mx1 = 100, mx0 = 100;
	while(cnt[mx0] != 0)	mx0 -= 1;
	while(mx1 > 0 and cnt[mx1] != 1)	mx1 -= 1;

	int ans = 0;
	rep(x, 1, 100) rep(y, x+1, 100) rep(z, y+1, 100) {
		++cnt[x];	++cnt[y];	++cnt[z];

		int mx = 0;
		if(cnt[x] == 1)	rmax(mx, x);
		if(cnt[y] == 1)	rmax(mx, y);
		if(cnt[z] == 1)	rmax(mx, z);

		bool valid = (mx != 0);
		rep(i, mx+1, 100) {
			if(cnt[i] == 1) {
				valid = false;
				break;
			}
		}
		ans += valid;

		--cnt[x];	--cnt[y];	--cnt[z];
	}
	cout << ans;
	return 0;
}
