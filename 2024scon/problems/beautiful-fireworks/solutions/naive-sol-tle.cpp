#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

vector<map<int, ll>> S;
vector<vi> graph;
vl W, D;

void dfs(int u, int prv) {
    for (int v : graph[u]) {
        if (v == prv) continue;
        D[v] = D[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    S.resize(n + 1);
    W.resize(n + 1);
    D.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> W[i];

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        D[i] = 0;
        dfs(i, i);
        
        ll sum = 0;
        for (int j = 1; j <= n; j++) sum += W[j] * D[j];
        ans = max(ans, sum);
    }

    cout << ans;
}
