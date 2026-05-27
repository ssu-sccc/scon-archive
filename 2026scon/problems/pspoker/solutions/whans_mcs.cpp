#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    vector<ll> A(n+1), B(n+1), I(n); iota(all(I), 1);
    for (int s = 1; s <= n; s++) cin >> A[s];
    for (int s = 1; s <= n; s++) cin >> B[s];
    
    sort(all(I), [&] (int a,int b) {
        if (B[a] * A[b] == B[b] * A[a]) return a < b;
        return B[a] * A[b] < B[b] * A[a];
    }); 
    cout << I.back() << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}