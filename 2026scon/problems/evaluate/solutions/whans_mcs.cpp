#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> A(n+1);
    for (int s = 1; s <= n; s++) cin >> A[s];
    auto jud = [&] (ll x) {
        ll c = 0, cost = 0;
        priority_queue<ll> pq;
        for (int s = 1; s <= n; s++) {
            if (A[s] >= x) {
                c++;
            } else {
                pq.push(A[s] - x);
                c--;
                if (c < 0) {
                    if (pq.size()) cost -= pq.top(), pq.pop();
                    else return false;
                    c += 2;
                }
            }
        }
        return cost <= m;
    };
    ll l = 0, r = 2e9+1;
    while (l+1 < r) {
        ll m = (l+r) >> 1;
        (jud(m) ? l : r) = m;
    }
    cout << l << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}