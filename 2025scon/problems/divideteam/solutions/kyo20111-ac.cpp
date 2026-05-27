#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1001001], b[1001001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    ll ans = 0, cnt = 0, s = 0;
    for(int i=n;i>=1;i--) {
        s += (a[i] ? 1 : -1) * b[i];
        if(i == 1 || s > 0) cnt++, ans += s;
    }
    cout << cnt << " " << ans;
}