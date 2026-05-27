#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool IsPrime(ll x){
    if(x < 2) return false;
    for(ll i=2; i*i<=x; i++) if(x % i == 0) return false;
    return true;
}

ll Pow(ll a, ll b, ll c){
    ll res = 1;
    for(a%=c; b; b>>=1, a=a*a%c) if(b & 1) res = res * a % c;
    return res;
}

vector<int> Generate(int n, int p){
    vector<int> res(n);
    for(int i=0; i<n; i++) res[i] = Pow(2, i, p);
    return res;
}

// 6*8192*8192 = 402653184
// 402653184/64 = 6291456
unsigned long long bs[6291456];
bool Validate(const vector<int> &a){
    memset(bs, 0, sizeof bs);
    for(int i=0; i<a.size(); i++){
        int sum = -1;
        for(int j=i; j<a.size(); j++){
            sum += a[j];
            if(bs[sum/64] >> (sum%64) & 1) return false;
            bs[sum/64] |= 1ull << (sum%64);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    for(int i=6*N+1; i>=1; i--){
        if(i != 6*N+1 && !IsPrime(i)) continue;
        auto v = Generate(N, i);
        if(Validate(v)){
            for(auto j : v) cout << j << " ";
            return 0;
        }
    }
    assert(false);
}