#ifndef _SNIPPETS_CPP_PRINT_HPP
#define _SNIPPETS_CPP_PRINT_HPP

#include <iostream>

template<typename ... Params>
void print(Params ... params) {
  (std::cerr << ... << params) << std::endl;
}

#endif
