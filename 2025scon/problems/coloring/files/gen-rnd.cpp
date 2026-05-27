#include "testlib.h"
#include "graph-generator.h"

using namespace graph_gen;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(3, 200'000);
    auto edges = make_undirected_simple_connected_graph(n, n);
    shuffle_edge(edges, false);
    relabel_vertex(n, edges);

    println(n);
    for (auto [u, v]: edges) println(u, v);
}
