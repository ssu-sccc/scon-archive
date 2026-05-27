#include "testlib.h"
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 100'000, "N");
    inf.readSpace();
    
    long long max_m = min(1LL * N * (N - 1) / 2, 200'000LL);
    int M = inf.readInt(0, max_m, "M");
    inf.readSpace();
    
    int Q = inf.readInt(1, 100'000, "Q");
    inf.readEoln();

    set<pair<int, int>> edges;

    for (int i = 0; i < M; i++) {
        int u = inf.readInt(1, N, "u");
        inf.readSpace();
        int v = inf.readInt(1, N, "v");
        inf.readEoln();

        // Check for self-loops
        ensuref(u != v, "Edge %d: Self-loop is not allowed (%d, %d)", i + 1, u, v);
        
        // Check for multiple edges
        int min_node = min(u, v);
        int max_node = max(u, v);
        ensuref(edges.find({min_node, max_node}) == edges.end(), "Edge %d: Multiple edges are not allowed between %d and %d", i + 1, min_node, max_node);
        
        edges.insert({min_node, max_node});
    }

    int query_type_2_count = 0;

    for (int i = 0; i < Q; i++) {
        int type = inf.readInt(1, 2, "type");
        inf.readSpace();
        
        if (type == 1) {
            int u = inf.readInt(1, N, "u");
            inf.readSpace();
            int x = inf.readInt(1, 100'000'000, "x"); 
            inf.readEoln();
        } else if (type == 2) {
            int d = inf.readInt(0, N - 1, "d");
            inf.readEoln();
            query_type_2_count++;
        }
    }

    // Ensure at least one query of type 2 exists
    ensuref(query_type_2_count >= 1, "There must be at least one query of type 2.");

    inf.readEof();

    return 0;
}