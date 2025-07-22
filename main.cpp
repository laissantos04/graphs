#include "include/Graph.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph *g = create_graph(5, true);

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 4);
    insert_edge(g, 4, 0);

    print_graph(g);

    destroy_graph(g);
    return 0;
}