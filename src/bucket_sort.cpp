/* Implementação do algoritmo Bucket Sort ordenando os vértices de um grafo
com base nos graus de cada vértice. */

#include "Graph.hpp"
#include "Algorithms.hpp"

void insert_list(Link *S, int degree, Vertex v) {
    Link node = new_node(v, S[degree]);
    S[degree] = node;
}

Link* clear_buckets(Link *S, int n, int min, int max) {
    Link *sorted = new Link[n];
    int index = 0;

    for (int i = min; i <= max; i++) {
        Link current = S[i];
        while (current != nullptr) {
            sorted[index++] = current;
            current = current->next;
        }
    }

    delete[] S;
    return sorted;
}

Link* bucket_sort(Graph *g, int min, int max) {

    int bucket_size = max + 1;
    Link *S = new Link[bucket_size];
    
    for (int i = 0; i < bucket_size; i++) {
        S[i] = nullptr;
    }

    for (int i = 0; i < g->V; i++) {
        // Para grafos não direcionados
        insert_list(S, g->degree[i], i);
    }

    return clear_buckets(S, g->V, min, max);
}