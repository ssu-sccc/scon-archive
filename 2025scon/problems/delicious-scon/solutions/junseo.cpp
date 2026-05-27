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

const int inf = 1e9 + 7;
const int maxn = 2e2 + 10;
const int maxm = 25e3 + 10;

int N, M, C, K;
int b[maxn];
vector<vector<int>> D[maxn];

int& get(int i, int k) {
	return D[i][k%C][k/C];
}

bool valid(int q, int r) {
	int temp = q*C + r;
	return (1 <= temp and temp <= M);
}

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> N >> M >> C >> K;	K /= C;
	rep(i, 0, N-1)	cin >> b[i];

	rep(i, 0, N) {
		D[i].resize(C);
		for(auto& D_ir : D[i])	D_ir.resize(M/C+1, -inf);
	}

	// D[i][k] := i분에 k도에 있을 떄의 답
	// D[i][r][q] := i분에 q*C+r도에 있을 때의 답
	// = M-|k-b[i]| + max( D[i-1][r][q-K .. q+K] )


	rep(t, 1, M)	get(0, t) = M - abs(b[0] - t);

	rep(i, 1, N-1) rep(r, 0, C-1) {
		deque<pii> mx;
		rep(q, 0, K-1) if(valid(q, r)) {
			auto p = pair{D[i-1][r][q], q};
			while(!mx.empty() and mx.back() < p)	mx.pop_back();
			mx.eb(p);
		}
		rep(q, 0, M/C) {
			while(!mx.empty() and mx[0].se+K < q)	mx.pop_front();
			if(valid(q+K, r)) {
				auto p = pair{D[i-1][r][q+K], q+K};
				while(!mx.empty() and mx.back() < p)	mx.pop_back();
				mx.eb(p);
			}

			int& dp = D[i][r][q];
			dp = (M - abs(b[i] - (q*C+r))) + mx[0].fi;
		}
	}

	int ans = 0;
	rep(t, 1, M)	rmax(ans, get(N-1, t));
	cout << ans;
	return 0;
}
