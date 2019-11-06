#ifndef _SNIPPETS_CPP_PRINT_HPP
#define _SNIPPETS_CPP_PRINT_HPP

#include <iostream>

namespace snip {

template<typename ... Params>
void print(Params ... params) {
  (std::cerr << ... << params) << std::endl;
}

template <typename Collection>
void printLoop(const Collection& collection) {
  for (const auto& item : collection) {
    std::cerr << item << std::endl;
  }
}

} // snip namespace

#endif
