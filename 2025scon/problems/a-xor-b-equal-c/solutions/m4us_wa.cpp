#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
const int MOD=1e9+7;
 
ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}
 
ll F[10101]={1};
 
ll ncr(ll n, ll r) { return F[n]*pw(F[r], MOD-2)%MOD*pw(F[n-r], MOD-2)%MOD; }
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=1;i<10101;i++) F[i]=F[i-1]*i%MOD;
    int a,b; cin >> a >> b;
    int n=(a+b)/3;
    if(a&1) return cout << 0, 0;
    cout << ncr(n, a/2) * pw(3,a/2) % MOD;
    return 0;
}
