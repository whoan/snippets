#ifndef _SNIPPETS_CPP_STD_INPUT_HPP
#define _SNIPPETS_CPP_STD_INPUT_HPP

#include <iostream>
#include <vector>

namespace snip {

template <typename T>
std::vector<T> createCollectionFromStdInput(std::size_t size) {
  std::vector<T> collection;
  T fromInput;
  for (std::size_t i=0; i < size; ++i) {
    std::cin >> fromInput;
    collection.push_back(fromInput);
  }
  return collection;
}

template <typename T>
std::vector<T> createCollectionFromStdInput() {
  std::vector<T> collection;
  T fromInput;
  while (std::cin >> fromInput) {
    collection.push_back(fromInput);
  }
  return collection;
}

template <typename T>
T takeFromStdInput() {
  T fromInput;
  std::cin >> fromInput;
  return fromInput;
}

} // snip namespace

#endif
