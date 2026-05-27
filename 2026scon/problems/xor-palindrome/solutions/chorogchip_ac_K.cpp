#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1'000'000'007;

long long mod_pow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m; int hf = m>>1;
    int basis[20] = {};
    int rank = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        int mask = 0;
        for (int j = 0; j < hf; ++j)
            mask |= ((s[j]-'0') ^ (s[m-j-1]-'0')) << j;

        int x = mask;
        for (int b = hf - 1; b >= 0; --b) {
            if (!(x & (1 << b))) continue;
            if (!basis[b]) {
                basis[b] = x;
                ++rank;
                break;
            }
            x ^= basis[b];
        }
    }

    long long ans = mod_pow(2, n - rank) - 1;
    if (ans < 0) ans += MOD;
    cout << ans;
    return 0;
}