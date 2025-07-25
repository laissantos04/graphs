#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "../include/Graph.hpp"

enum class Requirement { in, out, undirected };

Link *bucket_sort(Graph *g, int min, int max, Requirement req);
Link *kahns_algorithm(Graph *g);

#endif
