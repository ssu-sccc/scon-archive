#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[201010];
int n, q; ll sum = 0, sumi = 0;

bool sol(int ind, int x) {
    sum -= a[ind];
    sumi -= a[ind] * (ll)ind;
    sum += x;
    sumi += x * (ll)ind;
    a[ind] = x;
    if (sum % n) return false;
    ll mu = sum / n;
    ll left = n * (sum - n * mu);
    ll right = sumi - mu * n * (1+n) / 2;
    return left == right;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; sum += a[i];
        sumi += a[i] * (ll)i;
    }
    cin >> q;
    cout << (sol(1, a[1]) ? "Yes\n" : "No\n");
    while(q--) {
        int aa, bb; cin >> aa >> bb;
        cout << (sol(aa, bb) ? "Yes\n" : "No\n");
    }
}