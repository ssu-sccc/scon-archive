#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int SZ = 5050;
vector<int> primes;
vector<vector<int>> v(SZ, vector<int>(SZ, 0));

auto precompute() -> void {
    vector<bool> is_prime(SZ, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < SZ; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < SZ; j += i) is_prime[j] = false;
        }
    }

    for (int i = 2; i < SZ; i++) {
        int x = i;
        for (auto p: primes) {
            v[i][p] = v[i - 1][p];
            while (x % p == 0) {
                x /= p;
                v[i][p]++;
            }
        }
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int t;
    cin >> t;

    while (t--) {
        int n1, r1, n2, r2;
        cin >> n1 >> r1 >> n2 >> r2;

        bool is_coprime = true;
        for (int i: primes) {
            int v1 = v[n1][i] - v[r1][i] - v[n1 - r1][i];
            int v2 = v[n2][i] - v[r2][i] - v[n2 - r2][i];
            if (v1 and v2) {
                is_coprime = false;
                break;
            }
        }

        cout << is_coprime << endl;
    }
}
