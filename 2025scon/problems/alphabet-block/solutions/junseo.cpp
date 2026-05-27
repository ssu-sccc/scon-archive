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

	// 2S, 3C
	// 1S, 3C

	int s, c, o, n;	cin >> s >> c >> o >> n;
	s += n;
	c += o * 2;
	cout << min(s / 3, c / 6);
	return 0;
}
