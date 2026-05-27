#include<bits/stdc++.h>
#include "testlib.h"
#include "graph-validator.h"

using namespace std;
using namespace graph_val;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(3, 200'000, "n");
    inf.readEoln();

    vector<pair<int, int>> edges(n);
    for (auto &[u, v]: edges) {
        u = inf.readInt(1, n, "u");
        inf.readSpace();
        v = inf.readInt(1, n, "v");
        inf.readEoln();
    }

    assert(is_undirected_simple_connected_graph(n, edges));
    inf.readEof();
}