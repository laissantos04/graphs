#include "Graph.hpp"
#include <iostream>

using namespace std;

void init_degrees(Graph *g, int n) {
    if(g->is_directed) {
        g->out_degree = new int[n]();
        g->in_degree = new int[n]();
        g->degree = nullptr;        
    } else {
        g->degree = new int[n]();
        g->in_degree = nullptr;
        g->out_degree = nullptr;
    }
}

Graph *create_graph(int n, bool is_directed) {
    Graph *g = new Graph;
    g->V = n;
    g->E = 0;
    g->is_directed = is_directed;

    g->adj = new Link[n];

    for (int i = 0; i < n; i++) {
        g->adj[i] = nullptr;
    }

    init_degrees(g, n);
    
    return g;
}

void destroy_graph(Graph *g) {
    for (int i = 0; i < g->V; i++) {
        Link current = g->adj[i];
        while (current != nullptr) {
            Link next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] g->adj;
    delete[] g->out_degree;
    if (g->is_directed) delete[] g->in_degree;
    
    delete g;
}

Link new_node(Vertex v, Link next) {
    return new Node{v, next};
}

void insert_edge(Graph *g, Vertex v, Vertex w) {
    g->adj[v] = new_node(w, g->adj[v]);
    g->E++;

    if (g->is_directed) {
        g->in_degree[w]++;
        g->out_degree[v]++;
    } else {
        g->adj[w] = new_node(v, g->adj[w]);
        g->degree[v]++;
        g->degree[w]++;
    }
}

void print_graph(Graph *g) {
    cout << "Graph " << (g->is_directed ? "directed" : "not directed") << endl;
    
    for (int v = 0; v < g->V; v++) {
        cout << v << " (out=" << g->out_degree[v];
        if (g->is_directed) cout << ", in=" << g->in_degree[v];
        cout << "): ";

        for (Link node = g->adj[v]; node != nullptr; node = node->next) {
            cout << node->vertex << " ";
        }
        cout << endl;
    }
}