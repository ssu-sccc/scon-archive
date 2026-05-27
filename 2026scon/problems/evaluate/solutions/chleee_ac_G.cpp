#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll N;
ll v[202020];
bool f(ll t, ll B) {
    priority_queue<ll> pq;
    ll p = 0;
    for (int i = 1; i <= N; i++) {
        if (v[i] >= t) p++;
        else {
            p--; pq.push(-(t - v[i]));
            if (p < 0) {
                p += 2, B += pq.top(); pq.pop();
            }
        }
    }
    return B >= 0;
}

int main() {
    ll B;
    cin >> N >> B;
    for (int i = 1; i <= N; i++) cin >> v[i];
    
    ll l = 1, r = 4242424242;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        if (f(mid, B)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}