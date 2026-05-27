#include <bits/stdc++.h>
using namespace std;

int ask(const vector<int>& v) {
    cout << "? " << v.size();
    for (int x : v) cout << " " << x;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int askRange(int l, int r) {
    vector<int> v;
    for (int i = l; i <= r; i++) v.push_back(i);
    return ask(v);
}

int findLeftmost(int l, int r) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (askRange(l, m)) r = m;
        else l = m + 1;
    }
    return l;
}

void solve() {
    int n;
    cin >> n;

    int B = max(1, (int)sqrt(n));
    vector<pair<int,int>> blocks;
    for (int l = 1; l <= n; l += B) {
        int r = min(n, l + B - 1);
        blocks.push_back({l, r});
    }

    vector<int> good;
    for (int i = 0; i < (int)blocks.size(); i++) {
        auto [l, r] = blocks[i];
        if (askRange(l, r)) good.push_back(i);
    }

    int x = -1, y = -1;

    if ((int)good.size() >= 2) {
        auto [l1, r1] = blocks[good[0]];
        auto [l2, r2] = blocks[good[1]];
        x = findLeftmost(l1, r1);
        y = findLeftmost(l2, r2);
    } else if ((int)good.size() == 1) {
        auto [l1, r1] = blocks[good[0]];
        x = findLeftmost(l1, r1);

        int id = good[0];
        int nid = (id + 1 < (int)blocks.size() ? id + 1 : id - 1);
        if (0 <= nid && nid < (int)blocks.size()) {
            auto [l2, r2] = blocks[nid];
            if (askRange(l2, r2)) y = findLeftmost(l2, r2);
            else y = l2;
        } else {
            y = (x == 1 ? 2 : 1);
        }
    } else {
        x = 1;
        y = 2;
    }

    if (x > y) swap(x, y);
    cout << "! " << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}