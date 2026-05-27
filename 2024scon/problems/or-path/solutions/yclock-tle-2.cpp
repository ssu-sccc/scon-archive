#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300'005;
const int MAXM = 300'005;

int ud[MAXN];

void ufinit() { iota(ud, ud + MAXN, 0); }
int uf(int i) { return ud[i] == i ? i : uf(ud[i]); }
void uf(int a, int b) { ud[uf(b)] = uf(a); }

int A[MAXM], B[MAXM];
ll C[MAXM];

bitset<MAXM> ban;

ll Ans;

int N, M;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for(int i = M; i--;) cin >> A[i] >> B[i] >> C[i];

	for(int key = 60; key--;) {
		ufinit();

		for(int i = M; i--;) if(!ban[i] && !(C[i] >> key & 1))
			uf(B[i], A[i]);

		if(uf(1) == uf(N)) {
			for(int i = M; i--;) if(C[i] >> key & 1)
				ban[i] = true;
		} else {
			Ans |= 1ll << key;
		}
	}

	cout << Ans << '\n';

	return 0;
}