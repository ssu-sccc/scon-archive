#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> runs;
string best;

void dfs(int idx, string& cur) {
    if (idx == (int)runs.size()) {
        if (best.empty() || cur < best) best = cur;
        return;
    }

    auto [c, len] = runs[idx];
    for (int keep = 1; keep <= len; keep++) {
        cur.append(keep, c);
        dfs(idx + 1, cur);
        cur.resize(cur.size() - keep);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string T;
    cin >> n >> T;

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && T[i] == T[j]) j++;
        runs.push_back({T[i], j - i});
    }

    string cur;
    dfs(0, cur);

    cout << best << '\n';
    return 0;
}