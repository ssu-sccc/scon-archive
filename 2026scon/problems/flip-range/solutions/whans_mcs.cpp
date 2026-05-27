#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    string T; cin >> T;
    string Z = string(n, '0'), O = string(n, '1');
    for (int s = 1; s < n; s += 2) Z[s] = '1', O[s] = '0';
    auto cal = [&] (const string &S) {
        vector A(n, 0);
        for (int s = 0; s < n; s++) A[s] = S[s] != T[s];
        int cnt = 0;
        for (int s = 0, e = 0; s < n; s = e) {
            while (e < n && A[s] == A[e]) e++;
            if (A[s]) cnt++;
        } 
        return cnt;
    };
    cout << min(cal(Z), cal(O)) << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}