#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll INF = 3e18;

ll d[500500];
priority_queue<array<ll, 2>> pq;
vector<array<ll, 2>> v[500500];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for(int i=1;i<=m;i++) {
        ll x, y, z; cin >> x >> y >> z;
        v[x].push_back({y, z}), v[y].push_back({x, z});
    }
    for(int i=1; i<=n; i++) reverse(v[i].begin(), v[i].end());
 
    fill(d+1, d+1+n, INF);
    d[1] = 0, pq.push({0, 1});
    while(!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if(-c > d[u]) continue;
        for(auto [x, y] : v[u]) if((d[u]|y) < d[x]) d[x] = d[u]|y, pq.push({-d[x], x});
    }

    cout << d[n];
}
