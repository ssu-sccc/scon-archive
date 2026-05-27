#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n, a, b, s, e; cin >> n >> a >> b >> s >> e;
        if(s > e) swap(s, e);
        
        if(s == 1 && e == n) cout << (n-2)*a + min(a, b);
        else if(s == 1) cout << (n-2)*a + b;
        else if(s+1 == e) cout << (n-3)*a + b + min(a, b);
        else cout << (n-3)*a + b+b;
        cout << "\n";
    }
}
