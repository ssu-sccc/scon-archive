#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int n, a, b, s, e;
ll dp[1 << 20][20];

ll find(int B, int u) {
    if(__builtin_popcount(B) == 1) return u == e ? 0 : INF;

    auto &re = dp[B][u];
    if(re != -1) return re;
    re = INF;

    B ^= 1 << u;
    if(u && (B & (1 << u-1))) re = min(re, find(B, u-1) + a);
    if(B & (1 << u+1)) re = min(re, find(B, u+1) + a);

    if(B & 1) re = min(re, find(B, 0) + b);
    if(B & (1 << n-1)) re = min(re, find(B, n-1) + b);
    
    return re;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> a >> b >> s >> e;
        s--, e--;
    
        if(n > 20) while(1){}
        memset(dp, -1, sizeof dp);
        cout << find((1 << n)-1, s) << "\n";
    }
}