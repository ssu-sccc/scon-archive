#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    vector<ll> A(n+1);
    for (int s = 1; s <= n; s++) cin >> A[s];
    auto ask = [&] () {
        ll sum = reduce(all(A));
        if (sum % n) cout << "No\n";
        else {
            ll x = sum / n;
            auto B = A;
            for (int s = 1; s < n; s++) {
                ll g = x - B[s];
                B[s] += g;
                B[s+1] -= g;
                B[n-1] -= g;
                B[n] += g;
            }
            if (B[n-1] == x && B[n] == x) cout << "Yes\n";
            else cout << "No\n";
        }
    };
    int q; cin >> q;
    ask();
    while (q--) {
        int i, x; cin >> i >> x;
        A[i] = x;
        ask();
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}