#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = has_opt("n") ? max(3, opt<int>("n")) : rnd.next(3, 100000);
    int q = has_opt("q") ? opt<int>("q") : rnd.next(1, 100000);

    vector<pair<int, int>> edges;
    
    int h1 = 1;
    int h2 = 2;

    for (int i = 3; i <= n; i++) {
        edges.push_back({h1, i});
        edges.push_back({h2, i});
    }

    int m = edges.size();
    cout << n << " " << m << " " << q << "\n";

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end());

    for (auto e : edges) {
        int u = p[e.first - 1];
        int v = p[e.second - 1];
        if (rnd.next(0, 1)) swap(u, v);
        cout << u << " " << v << "\n";
    }

    int real_h1 = p[h1 - 1];
    int real_h2 = p[h2 - 1];

    for (int i = 0; i < q; ++i) {
        if (i % 2 == 0) {
            int u = rnd.next(0, 1) ? real_h1 : real_h2;
            int x = rnd.next(1, 100000000);
            cout << 1 << " " << u << " " << x << "\n";
        } else {
            cout << 2 << " " << 2 << "\n";
        }
    }

    return 0;
}