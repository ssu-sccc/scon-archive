#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int s, c, o, n;
	cin >> s >> c >> o >> n;
	s += n;
	c += 2 * o;
	cout << min(s / 3, c / 6) << '\n';
}