#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[100100], r[100100];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) r[a[i]] = i;

    ll ans1 = 0, ans2 = 0;
    for(int i=1;i<m;i++) ans1 += (r[i] - ans1 % n + n) % n;
    for(int i=n;i>=m;i--) ans2 += (r[i] - ans2 % n + n) % n;

    cout << (ans1 < ans2 ? "CW" : "CCW");
}