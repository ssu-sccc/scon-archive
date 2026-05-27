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

const int maxn = 1e5 + 10;

int N, M;
int A[maxn];

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio;

	cin >> N >> M;
	rep(i, 1, N) {
		int x;	cin >> x;
		A[x] = i;
	}

	int x1 = 0, y1 = 0;
	rep(i, 1, M-1) {
		if(A[i] < y1) {
			x1 += 1;
			y1 = 0;
		}
		y1 = A[i];
	}

	int x2 = 0, y2 = 0;
	rep2(i, N, M) {
		if(A[i] < y2) {
			x2 += 1;
			y2 = 0;
		}
		y2 = A[i];
	}

	cout << (pair{x1, y1} < pair{x2, y2} ? "CW" : "CCW");
	return 0;
}
