#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int p[500500];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for(auto &[x, y, z] : edges) cin >> x >> y >> z;

    ll mask = (1ll << 60) - 1;
    for(int i=59;i>=0;i--) {
        mask ^= (1ll << i);

        iota(p+1, p+1+n, 1);
        for(auto [x, y, z] : edges) if((z & mask) == z) p[find(x)] = find(y);
        if(find(1) != find(n)) mask ^= (1ll << i);
    }

    cout << mask;
}