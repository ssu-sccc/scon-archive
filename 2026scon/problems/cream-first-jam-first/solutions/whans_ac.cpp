#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    string S, T; cin >> T;
    for (int s = 0, e = 0; s < n; s = e) {
        while (e < n && T[s] == T[e]) e++;
        S += T[s];
    }
    int a = 0, b = 0;
    T.clear();
    for (auto c : S) {
        T += c;
        if (c == 'S') {
            if (T.size() == 3) (T[0] == 'C' ? a : b)++;
            T.clear();
        }
    }   
    cout << a << "\n" << b << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}