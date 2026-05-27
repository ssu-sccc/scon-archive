#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
using namespace std;

using ll = long long;

bool feasible_naive(const vector<ll>& A, ll B, ll T) {
    ll credit = 0;
    ll cost = 0;

    priority_queue<ll> pq;

    for (ll x : A) {
        if (x >= T) {
            credit++;
        } else {
            credit--;
            pq.push(x - T);

            if (credit < 0) {
                if (pq.empty()) return false;
                cost -= pq.top(); 
                pq.pop();
                credit += 2;      
            }
        }
    }
    return cost <= B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll B;
    cin >> N >> B;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll mx = *max_element(all(A));
    ll ans = 0;

    for (ll T = 0; T <= mx + B; T++) {
        if (feasible_naive(A, B, T)) ans = T;
    }

    cout << ans << '\n';
    return 0;
}