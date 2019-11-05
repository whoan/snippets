#ifndef _SNIPPETS_CPP_PRINT_HPP
#define _SNIPPETS_CPP_PRINT_HPP

#include <iostream>

namespace snip {

template<typename ... Params>
void print(Params ... params) {
  (std::cerr << ... << params) << std::endl;
}

} // snip namespace

#endif
