#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1001001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0;
    for(int i=n, j=a[n];i>=1;j = min(j, a[--i])) ans += j;
    cout << ans;
}