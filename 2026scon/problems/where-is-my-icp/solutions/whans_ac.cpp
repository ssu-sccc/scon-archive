#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n, m;
    string S, T; cin >> n >> S >> m >> T;
    vector<int> cnt(26);
    for (auto c : S) cnt[c - 'A']++;
    for (auto c : T) cnt[c - 'A']++;
    for (auto c : {'I', 'C', 'P', 'C'}) {
        if (!cnt[c - 'A']) {
            cout << "m4us sad\n";
            return;
        }
    }
    cout << "m4us happy\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}