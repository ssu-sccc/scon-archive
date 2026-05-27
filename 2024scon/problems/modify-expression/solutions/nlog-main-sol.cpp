#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int lit = n / 2 + 1;
    int ops = n / 2;
    vi A(lit), B(ops);
    auto a = A.begin(), b = B.begin();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            char c; cin >> c;
            *a++ = c == 'T';
        }
        else {
            char c; cin >> c;
            *b++ = c == '&';
        }
    }
    int target;
    {
        char c; cin >> c;
        target = c == 'T';
    }
    auto eval = [&]() {
        int a = A[0];
        for (int i = 1; i < lit; i++) {
            int b = A[i];
            if (!B[i - 1]) a |= b;
            else a &= b;
        }
        return a;
    };
    if (eval() == target) return cout << 0, 0;
    for (int i = 0; i < lit; i++) {
        int curr = A[i];
        A[i] = !curr;
        if (eval() == target) return cout << 1, 0;
        A[i] = curr;
    }
    for (int i = 0; i < ops; i++) {
        int curr = B[i];
        B[i] = !curr;
        if (eval() == target) return cout << 1, 0;
        B[i] = curr;
    }
    cout << 2;
}
