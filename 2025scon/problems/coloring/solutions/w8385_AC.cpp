#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> color(n + 1, -1);
    color[1] = 0;
    
    queue<int> q;
    q.push(1);
    
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto v: g[u]) {
            if (color[v] == -1) {
                color[v] = 1 xor color[u];
                q.emplace(v);
            } else if (color[v] == color[u]) {
                cout << "3" << endl;
                return 0;
            }
        }
    }
    
    cout << "2" << endl;
}
