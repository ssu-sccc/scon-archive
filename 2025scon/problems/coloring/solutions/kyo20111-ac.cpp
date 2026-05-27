#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, chk[200200];
vector<int> v[200200];

void dfs(int u, int p, int lev = 1) {
    if(chk[u]) {
        cout << (chk[u] % 2 != lev % 2 ? 3 : 2);
        exit(0);
    }
    chk[u] = lev;

    for(auto x : v[u]) if(x != p) dfs(x, u, lev+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dfs(1, 0);
}