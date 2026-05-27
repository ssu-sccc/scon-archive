#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<pair<int,int>> seg;
int ans;

bool ok(const string& t) {
    for (int i = 0; i + 1 < (int)t.size(); i++) {
        if (t[i] == t[i + 1]) return false;
    }
    return true;
}

void flip_range(string& t, int l, int r) {
    for (int i = l; i <= r; i++) {
        t[i] = (t[i] == '0' ? '1' : '0');
    }
}

void dfs(int idx, string& cur, int used) {
    if (idx == (int)seg.size()) {
        if (ok(cur)) ans = min(ans, used);
        return;
    }

    // 이 구간을 사용하지 않는 경우
    dfs(idx + 1, cur, used);

    // 이 구간을 사용하는 경우
    auto [l, r] = seg[idx];
    flip_range(cur, l, r);
    dfs(idx + 1, cur, used + 1);
    flip_range(cur, l, r); // 복구
}

int brute_force(string t) {
    s = t;
    n = (int)s.size();
    seg.clear();

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            seg.push_back({l, r});
        }
    }

    ans = (int)1e9;
    string cur = s;
    dfs(0, cur, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string T;
    cin >> N >> T;

    cout << brute_force(T) << '\n';
    return 0;
}