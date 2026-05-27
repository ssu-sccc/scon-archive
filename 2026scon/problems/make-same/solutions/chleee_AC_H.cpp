#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[202020], S1, S2;

void chk() {
    if(S1 % N != 0) { cout << "No" << endl;}
    else {
        ll X = S1 / N, Y = 0;
        if(S2 != (ll) X * (N*(N+1)/2)) { cout << "No" << endl;}        
        else cout << "Yes" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) S1 += A[i];
    for(int i=1; i<=N; i++) S2 += (ll)(N-i+1) * A[i];

    chk();
    ll Q; cin >> Q;
    while (Q--) {
        ll i, x; cin >> i >> x;
        S1 -= A[i];
        S2 -= (ll)(N-i+1) * A[i];
        S1 += x;
        S2 += (ll)(N-i+1) * x;
        A[i] = x;
        chk();
    }
}