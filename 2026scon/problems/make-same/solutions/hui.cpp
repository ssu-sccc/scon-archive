#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, Q, A[202020], S1, S2;

void Check(){
    if(S1 % N != 0){ cout << "No\n"; return; }
    if(N * (N + 1) / 2 * (S1 / N) == S2) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) S1 += A[i];
    for(int i=1; i<=N; i++) S2 += i * A[i];
    Check();
    cin >> Q;
    for(int q=1; q<= Q; q++){
        int i, x; cin >> i >> x;
        S1 -= A[i]; S2 -= i * A[i];
        A[i] = x;
        S1 += A[i]; S2 += i * A[i];
        Check();
    }
}