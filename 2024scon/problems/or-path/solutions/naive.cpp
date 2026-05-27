#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool chk[500500];
vector<array<ll, 2>> v[500500];

void dfs(int u, ll mask) {
    chk[u] = 1;
    for(auto [x, y] : v[u]) if(!chk[x] && (mask & y) == y) dfs(x, mask);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<array<ll, 3>> edges(m);

    ll mx = 0;
    for(int i=1;i<=m;i++) {
        ll x, y, z; cin >> x >> y >> z;
        v[x].push_back({y, z}), v[y].push_back({x, z});
        mx = max(mx, z);
    }

    assert(mx < (1 << 10));

    ll ans = 2e18;
    for(ll mask=0;mask<(1<<10);mask++) {
        memset(chk, 0, sizeof chk);
        dfs(1, mask);
        if(chk[n]) ans = min(ans, mask);
    }

    cout << ans;
}