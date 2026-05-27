#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

void solve(int b) {
    ll o = 0, e = 1, x = 24, y = 2, oo, ee, xx, yy;
    while (b) {
        if ((b & 1) == 1) {
            oo = o * x + e * y;
            ee = e * x + o * y;
            o = oo % MOD;
            e = ee % MOD;
        }
        xx = x * x + y * y;
        yy = (x * y) << 1;
        x = xx % MOD;
        y = yy % MOD;
        b >>= 1;
    }
    cout << e;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    solve(N);
}