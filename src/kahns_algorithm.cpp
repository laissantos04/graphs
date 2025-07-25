/* Implementação do algoritmo de Kahn para realizar ordenação topológica.
Para isso, considera-se o grau de entrada dos vértices para realizar a ordenação. */
#include "Graph.hpp"
#include "Algorithms.hpp"

/* Aloca um vetor temporário para armazenar os graus de entrada dos vértices,
evitando alterar a estrutura do grafo original.*/
int *temp_in_degree (Graph *g) {
    int *temp = new int[g->V];

    for (int i = 0; i < g->V; i++) {
        temp[i] = g->in_degree[i];
    }

    return temp;
}

Link* kahns_algorithm(Graph *g) {
    Link *order = new Link[g->V];
    int index = 0;
    int *temp = temp_in_degree(g);

    // Inicializa a fila
    int *queue = new int[g->V];
    int init = 0;
    int end = 0;

    /* Percorre todos os vértices do grafo G buscando os vértices de grau zero,
    e adiciona-os em uma fila.*/
    for (int i = 0; i < g->V; i++) {
        if (temp[i] == 0) {
            queue[end++] = i;
        }
    }

    /* Desenfileira os vértices de grau zero, removendo 1 do grau dos seus vértices adjacentes.
    Caso o vértice adjacente passe a ter grau zero, ele é enfileirado.*/
    while (init < end) {
        int v = queue[init++];
        order[index++] = new_node(v, nullptr); // Adiciona o vértice v à lista final de ordenação topológica
        
        // Percorre todos os vértices adjacentes a v na EAD
        for (Link adj = g->adj[v]; adj != nullptr; adj = adj->next) {
            int w = adj->vertex;
            temp[w]--;
            
            if (temp[w] == 0) {
                queue[end++] = w;
            }
        }
    }

    delete[] queue;
    delete[] temp;
    return order;
}