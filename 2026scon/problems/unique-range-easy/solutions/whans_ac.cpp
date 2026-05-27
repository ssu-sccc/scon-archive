#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    int m = (~n & 1 ? n+1 : n);
    int k = (m+1) >> 1;
    vector<int> A(m+1);
    for (int s = 1; s < k; s++) A[s] = (k-s) * (~s & 1 ? -1 : 1);
    
    for (int s = k+1; s <= m; s++) A[s] = (s-k) * (s & 1 ? -1 : 1);
    for (int s = 1; s <= n; s++) cout << A[s] << " "; cout << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}