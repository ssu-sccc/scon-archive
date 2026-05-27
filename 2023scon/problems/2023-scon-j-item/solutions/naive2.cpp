#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[200200];
bool chk[200200];

int solve(int u, ll last) {
    int re = u;
    for(int i=1;i<=n;i++) if(!chk[i] && (last & ((1 << u)-1)) == (a[i] & ((1 << u)-1))) {
        chk[i] = 1;
        re = max(re, solve(u+1, a[i]));
        chk[i] = 0;
    }
    return re;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    int ans = 0;
    for(int i=1;i<=n;i++) {
        chk[i] = 1;
        ans = max(ans, solve(1, a[i]));
        chk[i] = 0;
    }
    cout << ans;
}