#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[500500];
ll s[500500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n+k;i++) s[i] = s[i-1] + a[i];

    assert(n+k < 30);

    ll ans = 0;
    for(int i=0;i<(1<<n+k);i++) {
        vector<int> v(1, 0);
        for(int j=0;j<n+k;j++) if((1 << j) & i) v.push_back(j+1);

        ll sum = 0;
        for(int i=1;i<v.size();i++) sum += s[v[i]]-s[max(v[i]-k, v[i-1])];
        ans = max(ans, sum);
    }
    cout << ans;
}