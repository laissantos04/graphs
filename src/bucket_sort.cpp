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

/* Caso o grafo seja direcionado, podemos determinar qual o critério
de ordenação (o grau de entrada ou de saída) com base no objetivo da aplicação.
Caso não seja direcionado, deve-se usar 'undirected'. */

Link* bucket_sort(Graph *g, int min, int max, Requirement req) {

    int bucket_size = max + 1;
    Link *S = new Link[bucket_size];
    
    for (int i = 0; i < bucket_size; i++) {
        S[i] = nullptr;
    }

    if (!g->is_directed) {
        for (int i = 0; i < g->V; i++) {
            insert_list(S, g->degree[i], i);
        }
    } else {
        for (int i = 0; i < g->V; i++) {
            if (req == Requirement::out) {
                insert_list(S, g->out_degree[i], i);
            } else if (req == Requirement::in) {
                insert_list(S, g->in_degree[i], i);
            }
        }
    }

    return clear_buckets(S, g->V, min, max);
}