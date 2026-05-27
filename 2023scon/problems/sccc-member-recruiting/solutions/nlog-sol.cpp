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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, x; cin >> n >> k >> x;

    vector<vi> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        while (c--) {
            int a; cin >> a;
            vec[i].push_back(--a);
        }
    }

    vpii score;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        score.emplace_back(a, i);
    }

    sort(all(score), greater<>());

    vector<vector<vi>> state;

    state.emplace_back(); // init: k-empty sets
    for (int i = 0; i < k; i++) state.back().emplace_back();

    for (const auto &[_, i] : score) {
        unordered_map<string, int> vis;
        vector<vector<vi>> next;
        for (const auto &before : state) {
            for (int j : vec[i]) {
                if (before[j].size() < x) {
                    auto tmp = before;
                    tmp[j].push_back(i);

                    stringstream ss;
                    for (const auto &a : tmp) ss << setw(2) << setfill('0') << a.size();
                    string key = ss.str();

                    if (vis.count(key)) continue; // 각각의 스터디 그룹에 배정된 수가 같으면, 내부적으로 어떤 식으로 배열되어 있는지는 고려하지 않음 (이거 처리 안 하면 2^20에다가 뭔가 더 붙을듯)

                    vis[key] = 1;
                    next.emplace_back(tmp);
                }
            }
        }

        if (!next.empty()) state.swap(next);
    }

    auto ans = state.front();
    for (const auto &i : ans) {
        cout << i.size() << " ";
        for (int j : i) cout << j << " ";
        cout << "\n";
    }
}
