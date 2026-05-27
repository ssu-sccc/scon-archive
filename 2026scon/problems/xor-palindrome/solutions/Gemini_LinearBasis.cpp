#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

struct LinearBasis {
    vector<int> basis;
    int r;
    LinearBasis(int m) : basis(m, 0), r(0) {}
    void insert(int x) {
        for (int i = basis.size() - 1; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!basis[i]) {
                    basis[i] = x;
                    r++;
                    return;
                }
                x ^= basis[i];
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    LinearBasis lb(M);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int val = 0;
        for (int j = 0; j < M; j++) {
            if (s[j] == '1') {
                val |= (1 << j);
            }
        }
        lb.insert(val);
    }

    int dim_pal = (M + 1) / 2;
    for (int i = 0; i < M / 2; i++) {
        int p = (1 << i) | (1 << (M - 1 - i));
        lb.insert(p);
    }
    if (M % 2 == 1) {
        lb.insert(1 << (M / 2));
    }

    int dim_sum = lb.r;
    ll exponent = (ll)N + dim_pal - dim_sum;
    
    cout << (power(2, exponent) - 1 + MOD) % MOD << "\n";

    return 0;
}