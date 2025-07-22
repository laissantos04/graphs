#ifndef GRAPH_HPP
#define GRAPH_HPP

struct Node;
using Link = Node*;

struct Node {
  int vertex;
  Link next;
};

using Vertex = int;

struct Graph {
  int V;
  int E;
  Link *adj;
  bool is_directed;
  int *degree;

  int *in_degree;
  int *out_degree;
};

Graph *create_graph(int n, bool is_directed);
void destroy_graph(Graph *g);
Link new_node(Vertex v, Link next);
void insert_edge(Graph *g, Vertex v, Vertex w);
void print_graph(Graph *g);
#endif


