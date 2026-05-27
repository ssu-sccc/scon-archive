#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    auto parse = [&](string s) {
        int a = atoi(s.substr(0, 2).c_str()), b = atoi(s.substr(3, 2).c_str());
        return a * 60 + b;
    };

    vector<vector<tuple<int, int, int, int>>> vec(n);
    for (auto &v : vec) {
        int m; cin >> m;
        v.resize(m);
        for (auto &[a, b, c, d] : v) {
            cin >> a >> b;
            b--;
            string x, y; cin >> x >> y;
            c = parse(x), d = parse(y);
        }
    }

    vector<tuple<int, int, int, int, int>> all;
    int idx = 0;
    for (const auto &v : vec) {
        for (const auto &[a, b, c, d] : v) {
            all.emplace_back(a, b, c, d, idx);
        }
        idx++;
    }

    int ans = 0;
    int k = all.size();
    for (int bit = 0; bit < (1 << k); bit++) {
        int fail = 0, credit = 0;
        vector<int> use(n);
        vector<vector<pair<int, int>>> day(7);
        for (int i = 0; i < k; i++) {
            if (bit & (1 << i)) {
                auto [a, b, c, d, e] = all[i];
                if (use[e]) fail = 1;
                use[e] = 1;
                credit += a;
                day[b].emplace_back(c, d);
            }
        }
        if (fail) continue;
        if (credit != 22) continue;
        for (auto &v : day) {
            sort(v.begin(), v.end());
            int prv = -1;
            for (const auto &[a, b] : v) {
                if (prv > a) fail = true;
                prv = b;
            }
        }
        if (fail) continue;
        ans++;
    }

    cout << ans;
}
