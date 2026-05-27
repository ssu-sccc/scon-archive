#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll b = n * n;
    for (int s = 1; s <= n; s++) cout << b + 2 * s - 1 << " \n"[s == n];
    return 0;
}