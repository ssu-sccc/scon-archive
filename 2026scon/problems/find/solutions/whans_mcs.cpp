#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int n; cin >> n;
    auto ask = [&] (int l,int r) {
        cout << "? " << r-l+1 << " ";
        for (int s = l; s <= r; s++) cout << s << " "; cout << endl;
        int x; cin >> x;
        return x;
    };
    int l = 0, r = n;
    while (l+1 < r) {
        int m = (l+r) >> 1;
        (ask(1, m) ? r : l) = m;
    }
    int L = 1, R = n+1;
    while (L+1 < R) {
        int M = (L+R) >> 1;
        (ask(M, n) ? L : R) = M;
    }
    cout << "! " << r << " " << L << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}