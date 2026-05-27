#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
const ll mod = 1e9 + 7;
ll dp[2][1 << 10];
void solve(){
    int n, m; cin >> n >> m;
    vector<string> A(n+1);
    for (int s = 1; s <= n; s++) cin >> A[s];
    vector<ll> B(n+1);
    for (int s = 1; s <= n; s++) {
        for (int e = 0; e < m/2; e++) 
            if (A[s][e] != A[s][m-e-1]) B[s] |= 1 << e;
    }
    dp[0][0] = 1;
    auto push = [&] (ll &x,ll v) { x = (x + v) % mod; };
    for (int s = 1; s <= n; s++) {
        memset(dp[s & 1], 0, sizeof dp[s & 1]);
        for (int e = 0; e < 1 << (m/2); e++) {
            push(dp[s & 1][e], dp[(s-1) & 1][e]);
            push(dp[s & 1][e ^ B[s]], dp[(s-1) & 1][e]);
        }
    }
    push(dp[n & 1][0], mod-1);
    cout << dp[n & 1][0] << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}