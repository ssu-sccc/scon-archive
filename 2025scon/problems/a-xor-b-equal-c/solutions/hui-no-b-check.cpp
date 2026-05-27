#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;

ll Pow(ll a, ll b){
    ll res = 1;
    for(; b; b>>=1, a=a*a%MOD) if(b & 1) res = res * a % MOD;
    return res;
}

ll Fac(int n){
    ll res = 1;
    for(int i=1; i<=n; i++) res = res * i % MOD;
    return res;
}

ll Inv(int n){ return Pow(Fac(n), MOD-2); }

ll C(int n, int r){ return Fac(n) * Inv(r) % MOD * Inv(n-r) % MOD; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    assert((a + b) % 3 == 0);
    if(a % 2 != 0 || a/2 > (a+b)/3){ cout << 0; return 0; }
    cout << C((a+b)/3, a/2) * Pow(3, a/2) % MOD;
}