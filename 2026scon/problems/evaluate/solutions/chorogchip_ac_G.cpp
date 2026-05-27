#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[201010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, b; cin >> n >> b;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll lo = 0, hi = 3'000'000'000LL;
    while (lo < hi) {
        priority_queue<int> pq;
        ll md = lo + hi + 1 >> 1;
        ll sum = 0;
        int credit = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= md) ++credit;
            else { --credit; pq.push(a[i] - md); }
            if (credit >= 0) continue;
            sum += -pq.top(); pq.pop();
            credit += 2;
        }
        if (sum <= b) lo = md;
        else hi = md - 1;
    }
    cout << lo;
}