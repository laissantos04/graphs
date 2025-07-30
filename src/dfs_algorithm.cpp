#include <string>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Structs.hpp"

/* Implementação do algoritmo de busca em profundidade em grafos, com o objetivo de percorrer o grafo.
Para cada vértice, a busca segue por um vizinho não visitado, e depois os vizinhos desse vizinho, até não ter mais vizinhos disponíveis.
A implementação usa como referência o algoritmo do Cormen. */

/* Calcula o low do vértice v: é o menor tempo de descoberta alcançável a partir de um vértice
usando zero ou mais arestas de árvore e no máximo 1 aresta de retorno para um ancestral. */
int min(int low_v, int low_u) {

}

/* Recebe um grafo conexo e um vértice inicial como parâmetros*/
DFSResult* dfs(Graph *g, Vertex v, DFSResult *R) {
    R->timer++; 
    R->time_in[v] = R->low_v[v] = R->timer;
    R->color_v[v] = "gray";

    // Percorre todos os vizinhos do vértice v
    for (Link u = g->adj[v]; u != nullptr; u = u->next) {
        R->parent[u->vertex] = v;
        // Se o vértice vizinho ainda não foi explorado, chama recursivamente a função
        if (R->color_v[u->vertex] == "white") { 
            dfs(g, u->vertex, R);
            R->low_v[v] = min(R->low_v[v], R->low_v[u->vertex]); 
        } 
    }

    // Se já explorou todos os vértices adjacentes, marca como preto
    R->color_v[v] = "black"; 
    R->timer++;
    R->time_out[v] = R->timer;
}

/* Se o grafo não for conexo, a busca em profundidade pode determinar os componentes conexos dele. */
