#ifndef _SNIPPETS_GRAPH_HPP
#define _SNIPPETS_GRAPH_HPP

#include <iostream>

namespace snip {

template <typename AdjacencyList>
void printGraph(const AdjacencyList& graph) {
  for (const auto& pair: graph) {
    std::cout << pair.first;
    for (const auto& vertex : pair.second) {
      std::cout << "-> " << vertex;
    }
    std::cout << std::endl;
  }
}

} // snip namespace

#endif
