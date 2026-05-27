#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while(tc--) {
        ll n, a = 0, b = 1, s, e; cin >> n >> s >> e;
        
        if(s == 1 || s == n) cout << (n-2)*a + b;
        else if(abs(s-e) == 1) cout << (n-3)*a + b + min(a, b);
        else cout << (n-3)*a + b+b;
        cout << "\n";
    }
}
