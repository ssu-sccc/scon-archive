#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, K, A[202020];

bool Check(ll T){
    ll C = 0, X = 0;
    priority_queue<ll, vector<ll>, greater<>> Q;
    for(int i=1; i<=N; i++){
        if(A[i] >= T) C++; else C--, Q.push(T-A[i]);
        if(C < 0 && Q.empty()) return false;
        if(C < 0) C += 2, X += Q.top(), Q.pop();
    }
    return X <= K;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> A[i];
    ll l = 0, r = 2e9;
    while(l < r){
        ll m = (l + r + 1) / 2;
        if(Check(m)) l = m;
        else r = m - 1;
    }
    cout << l;
}