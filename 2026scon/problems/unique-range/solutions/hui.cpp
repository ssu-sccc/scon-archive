#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool IsPrime(ll x){
    if(x < 2) return false;
    for(ll i=2; i*i<=x; i++) if(x % i == 0) return false;
    return true;
}

ll N, A[10101], S[10101], P;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=N+1; !P; i++) if(IsPrime(i)) { P = i; break; }
    for(int i=1; i<=N; i++) S[i] = 2 * P * i + (i * i % P);
    for(int i=1; i<=N; i++) A[i] = S[i] - S[i-1];
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}