#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    string T; cin >> T;
    vector<P> A;
    for (int s = 0, e = 0; s < n; s = e) {
        while (e < n && T[s] == T[e]) e++;
        A.push_back({T[s], e-s});
    }
    vector<int> S;
    for (int s = 1; s < A.size(); s++) {
        if (A[s-1][0] > A[s][0]) A[s-1][1] = 1;
    }
    A.back()[1] = 1;
    string ans = "";
    for (auto [c, cnt] : A) ans += string(cnt, char(c));
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    while (T--) solve();
}