#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

vector<ll> v;

int main() {
    int n; cin >> n; v.resize(n);
    for (auto &i : v) cin >> i; reverse(v.begin(), v.end());

    ll ret = 0;
    ll Min = 1010101;
    for (auto &i : v) {
        Min = min(Min, i), ret += Min;
    }
    cout << ret << endl;
}