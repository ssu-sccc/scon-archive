#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = array<ll,2>;
void solve(){
    int a, b, c, h; cin >> a >> b >> c >> h;
    int ans = 1'557'884'844;
    for (int i : {0, 1}) for (int j : {0, 1}) for (int k : {0, 1}) {
        int use = i * a / 2 + j * b/2 + k * c/2;
        if (use < h) ans = min(ans, a+b+c - i * a/2 - j * b/2 - k * c/2);
    } 
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; 
    while (T--) solve();
}