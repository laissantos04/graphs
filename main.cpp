#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph *g = create_graph(5, false);

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 4);
    insert_edge(g, 2, 4);

    print_graph(g);

    cout << "Vértices ordenados por grau: " << endl;
    
    Link *sorted_by_degrees = new Link[g->V];
    sorted_by_degrees = bucket_sort(g, 1, 3);

    for (int i = 0; i < g->V; i++) {
        if (sorted_by_degrees[i] != nullptr) {
            cout << "Vertex[" << sorted_by_degrees[i]->vertex << "]" << endl;
        }
    }

    delete[] sorted_by_degrees;
    destroy_graph(g);
    return 0;
}