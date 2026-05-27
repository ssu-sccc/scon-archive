#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ed; cin >> n >> ed;
    vector A(n + 1, 0);
    for(int s = 0, t = 0; s < n; s++)cin >> t, A[t] = s;
    ll CW = 0;
    for(int s = 1; s < ed; s++){
        ll nx = CW / n * n + A[s];
        if(nx < CW)nx += n;
        CW = nx;
    }
    ll CCW = 0;
    for(int s = n; s >= ed; s--){
        ll nx = CCW / n * n + A[s];
        if(nx < CCW)nx += n;
        CCW = nx;
    }
    cout << (CW < CCW ? "CW" : "CCW") << "\n";
}