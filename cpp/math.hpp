#ifndef _SNIPPETS_MATH_HPP
#define _SNIPPETS_MATH_HPP

#include <cmath>

namespace snip {

int getMostSignificantDigit(int x) {
  return x / std::pow(10, int(snip::log10(x)));
}

int getLeastSignificantDigit(int x) {
  return x % 10;
}

} // snip namespace

#endif
