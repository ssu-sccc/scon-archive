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

const int maxn = 1e6 + 10;

int N, A[maxn], B[maxn];
ll suf[maxn];
vector<pll> sorted;

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> N;
	rep(i, 1, N)	cin >> A[i];
	rep(i, 1, N)	cin >> B[i];

	rep(i, 1, N)	if(A[i] == 0)	B[i] *= -1;
	rep2(i, N, 1) {
		suf[i] = suf[i+1] + B[i];
		if(i > 1)	sorted.eb(suf[i], i);
	}

	int cnt = 1;
	ll sum = suf[1];

	sort(all(sorted), greater<pll>());
	for(auto& [s, i] : sorted) {
		if(s <= 0)	break;
		cnt += 1;
		sum += s;
	}
	cout << cnt << ends << sum;
	return 0;
}
