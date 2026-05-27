#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    ll n; cin >> n;
    if (n == 4) {
        cout << "2 4 8 16\n";
        return;
    }
    vector<int> p(2*n+1);
    for (int s = 2; s <= 2*n; s++) if (!p[s]) {
        for (int e = s*s; e <= 2*n; e += s) p[e] = 1;
    }
    int k = 0;
    for (int s = n+1; s <= 2*n && !k; s++) if (!p[s]) k = s;
    vector<ll> S(n+1);
    for (ll s = 1; s <= n; s++) S[s] = 2 * k * s + s * s % k;
    for (int s = 1; s <= n; s++) cout << S[s] - S[s-1] << " "; cout << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}