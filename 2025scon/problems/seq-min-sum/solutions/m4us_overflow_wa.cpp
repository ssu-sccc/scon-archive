#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    reverse(v.begin(), v.end());

    int ans = 0, mn = 1e9;
    for(int i : v) mn = min(mn, i), ans += mn;
    cout << ans;
    return 0;
}