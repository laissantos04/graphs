#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph *g = create_graph(5, true);

    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 1, 4);
    insert_edge(g, 2, 4);

    print_graph(g);

    Link* v = kahns_algorithm(g);
    cout << "Ordenacao topologica:" << endl;

    for (int i = 0; i < g->V; i++) {
        cout << "[" << v[i]->vertex << "] -> ";
    }
    
    destroy_graph(g);
    return 0;
}