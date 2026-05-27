#include <bits/stdc++.h>

using ll = long long;
using namespace std;
#define MOD 1000000007
#define pii pair<int, int>

int T = 1, SZ = 1e8;

int par[200200];
vector<int> G[200200];
vector<pii> edges;

void init(int n) {
    for(int i = 1; i <= n; i++) par[i] = i;
}

int find(int n) {
    if(n == par[n]) return n;
    return par[n] = (find(par[n]));
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    par[a] = b;
}

int dfs(int n, int p, int d) {
    if(n == d) return 1;

    for(auto i : G[n]) {
        if(i == p) continue;
        
        int t = dfs(i, n, d);
        if(t) return t+1;
    }

    return 0;
}

void solve() {
    int N; cin >> N;

    init(N);

    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        edges.push_back({a, b});
    }

    for(auto [a, b] : edges) {
        if(find(a) == find(b)) {
            cout << 2+dfs(a, -1, b)%2 << "\n";
            return;
        }
        merge(a, b);
    }
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);

    while(T--) solve();
}    
