#ifndef _SNIPPETS_BFS_HPP
#define _SNIPPETS_BFS_HPP

#include <unordered_map>
#include <queue>

namespace snip {

template <typename GraphAdjacencyList, typename VertexType, typename Tree = std::unordered_map<VertexType, VertexType>>
class BreadthFirstTree {
  VertexType source;
  Tree tree;

public:
  BreadthFirstTree(GraphAdjacencyList graph, VertexType source) : source(std::move(source)) {
    // use BFS to create a Breadth First Tree
    std::queue<VertexType> queue;
    queue.push(this->source);

    while (queue.size()) {
      auto vertex = queue.front();
      queue.pop();
      for (const auto& adjacentVertex : graph.at(vertex)) {
        if (!tree.count(adjacentVertex) && adjacentVertex != this->source) {
          queue.push(adjacentVertex);
          tree[adjacentVertex] = vertex;
        }
      }
    }
  }

  int getDistance(const VertexType& target) {
    int count = 0;
    for (auto current = target; current != source; current = tree.at(current)) {
      ++count;
    }
    return count;
  }
};

// helper for compilers not supporting C++17 to avoid providing template parameters (C++14 is needed)
template <typename GraphAdjacencyList, typename VertexType>
auto makeBreadthFirstTree(GraphAdjacencyList graph, VertexType source) {
  return BreadthFirstTree<GraphAdjacencyList, VertexType>(std::move(graph), std::move(source));
}

} // snip namespace

#endif
