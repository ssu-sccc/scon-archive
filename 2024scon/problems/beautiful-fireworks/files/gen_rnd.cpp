#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// 1-based
vector<pair<int, int>> MakeTree(int n) {
    if (n == 1) return {};
    if (n == 2) return {{1, 2}};

    vector<int> a(n - 2), deg(n + 1);
    for (auto &i: a) i = rnd.next(1, n);
    for (auto i: a) deg[i]++;

    vector<pair<int, int>> res;
    priority_queue<int> pq;
    for (int i = n; i; i--) if (!deg[i]) pq.emplace(i);
    for (auto i: a) {
        int j = pq.top();
        pq.pop();
        res.emplace_back(min(i, j), max(i, j));
        if (!--deg[i]) pq.push(i);
    }
    int u = pq.top();
    pq.pop();
    int v = pq.top();
    pq.pop();
    res.emplace_back(u, v);
    return res;
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(2, 1000);
    cout << n << "\n";
    auto graph = MakeTree(n);
    for (auto &[a, b]: graph) if (rnd.next(0, 1)) swap(a, b);
    shuffle(graph.begin(), graph.end());
    for (auto [a, b]: graph) cout << a << " " << b << "\n";
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << rnd.next(1, 1'000'000);
    }
    cout << "\n";
}
