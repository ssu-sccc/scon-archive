#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    vector<ll> A(n+1), B(n+1);
    for (int s = 1; s <= n; s++) cin >> A[s];
    ll sum = reduce(all(A));
    ll w = 0;
    auto ask = [&] () {
        if (w != sum / n * n * (n+1) / 2) cout << "No\n";
        else cout << "Yes\n";
    };
    for (int s = 1; s <= n; s++) w += s * A[s];
    ask();
    int q; cin >> q;
    for (int s = 0; s < q; s++) {
        ll i, x; cin >> i >> x;
        sum = sum - A[i] + x;
        w = w - i * A[i] + i * x;
        A[i] = x;
        ask();
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}
