#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1e9 + 7;
const int N = 3030;
ll C[N][N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    C[0][0] = 1;
    for(int s = 1; s < N; s++){
        C[0][s] = 1;
        for(int e = 1; e <= s; e++)C[e][s] = (C[e][s - 1] + C[e - 1][s - 1]) % mod;
    }
    int a, b; cin >> a >> b;
    if(a & 1)cout << "0\n";
    else{
        a >>= 1;
        b -= a;
        b /= 3;
        ll r = 1;
        for(int s = 0; s < a; s++)r = r * 3 % mod;
        cout << C[b][a + b] * r % mod << "\n"; 
    }
}
