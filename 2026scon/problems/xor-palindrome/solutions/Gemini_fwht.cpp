#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void fwht(vector<ll>& a, bool inv) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                ll u = a[i + j];
                ll v = a[i + len + j];
                if (!inv) {
                    a[i + j] = u + v;
                    a[i + len + j] = u - v;
                } else {
                    a[i + j] = (u + v) % MOD;
                    a[i + len + j] = (u - v + MOD) % MOD;
                }
            }
        }
    }
    if (inv) {
        ll inv_n = power(n, MOD - 2);
        for (int i = 0; i < n; i++) {
            a[i] = (a[i] * inv_n) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int m = M / 2;
    int size = 1 << m;
    vector<ll> A(size, 0);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int val = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] != s[M - 1 - j]) {
                val |= (1 << j);
            }
        }
        A[val]++;
    }

    fwht(A, false);

    ll pow2N = power(2, N);
    for (int i = 0; i < size; i++) {
        if (A[i] == N) A[i] = pow2N;
        else A[i] = 0;
    }

    fwht(A, true);

    cout << (A[0] - 1 + MOD) % MOD << "\n";

    return 0;
}