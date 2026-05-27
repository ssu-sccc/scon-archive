#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int mod = 1'000'000'007;

vector<int> fct(1e6 + 1, 1);
vector<int> inv(1e6 + 1, 1);

auto modexp(int a, int b) -> int {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

auto precompute() -> void {
    for (int i = 2; i <= 1e6; i++) fct[i] = fct[i - 1] * i % mod;
    inv[1e6] = modexp(fct[1e6], mod - 2);
    for (int i = 1e6 - 1; i >= 2; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}

auto nCr(int n, int r) -> int {
    if (n < r) return 0;
    return fct[n] * inv[r] % mod * inv[n - r] % mod;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i <= n; i += 2) {
        res += modexp(24, n - i) * nCr(n, i) % mod * modexp(2, i) % mod;
        res %= mod;
    }
    cout << res << endl;
}
