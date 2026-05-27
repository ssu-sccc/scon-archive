#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[500500], r[500500];
ll ans[500500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) r[a[i]] = i;

    for(int i=1;i<=n;i++) {
        int x = r[i];
        ans[a[i]] += x-i, ans[i] += x-i;
        cout << ans[i] << " ";
        swap(a[i], a[x]), r[a[x]] = x;
    }
}
