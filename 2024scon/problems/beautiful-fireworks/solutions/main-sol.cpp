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
ll sum;

ll dfs(int u, int prv) {
    ll ret = W[u];
    for (int v : graph[u]) {
        if (v == prv) continue;
        D[v] = D[u] + 1;
        ret += S[u][v] = dfs(v, u);
    }
    return ret;
}

ll ans;
void solve(int u, int prv, ll curr) {
    ans = max(ans, curr);
    for (int v : graph[u]) {
        if (v == prv) continue;
        solve(v, u, curr + sum - 2 * S[u][v]);
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
    dfs(1, 1);

    for (int i = 1; i <= n; i++) ans += W[i] * D[i];

    sum = accumulate(all(W), 0LL);
    solve(1, 1, ans);

    cout << ans;
}
