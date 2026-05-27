#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    int n; cin >> n;
    vector<ll>A(n);
    for(ll &i : A)cin >> i;
    ll mn = 1e18, ans = 0;
    for(int s = n - 1; s >= 0; s--){
        mn = min(mn, A[s]);
        ans += mn;
    }
    cout << ans;
}
