#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int mod = 1e9 + 7;

auto modexp(int b, int e) -> int {
    int r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}

auto inv(int x) -> int {
    return modexp(x, mod - 2);
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a % 2) {
        cout << 0 << endl;
        return 0;
    }

    int n = (a + b) / 3;
    int r = a / 2;
    if (n < r) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    cout << fact[n] * inv(fact[r]) % mod * inv(fact[n - r]) % mod * modexp(3, r) % mod << endl;
}
