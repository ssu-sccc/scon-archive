#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end());
    
    vector<pair<int, int>> edges(n);
    for (int i = 0; i < n; i++) {
        edges[i] = {a[i], a[(i + 1) % n]};
    }
    shuffle(edges.begin(), edges.end());
    
    println(n);
    for (auto &[u, v]: edges) {
        println(u, v);
    }
    
    return 0;
}
