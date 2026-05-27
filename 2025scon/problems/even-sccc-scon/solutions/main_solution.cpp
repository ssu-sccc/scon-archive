#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1'000'000'007;
const int N = 1'000'101;
ll cnt = 0;
ll dp[N], pw[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    pw[0] = 1; dp[1] = 24;
    for(int s=1; s<=n; s++)pw[s] = pw[s-1] * 26 % mod;
    for(int s=2; s<=n; s++)dp[s] = (2 * pw[s-1] % mod + (22 * dp[s-1]) % mod) % mod;
    cout << dp[n];
}