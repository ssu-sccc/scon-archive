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
        C[s][0] = 1;
        for(int e = 1; e <= s; e++)C[s][e] = (C[s - 1][e] + C[s - 1][e - 1]) % mod;
    }
    int a, b; cin >> a >> b;
    if(a & 1)cout << "0\n";
    else{
        a >>= 1;
        b -= a;
        if(b < 0 || b % 3)cout << "0\n";
        else{
            b /= 3;
            ll r = 1;
            for(int s = 0; s < a; s++)r = r * 3 % mod;
            cout << C[a + b][b] * r % mod << "\n"; 
        }
    }
}