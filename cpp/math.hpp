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

// tail-recursive factorial: https://stackoverflow.com/a/2693719
int factorial( int n, int acc = 1 ) {
    if ( n == 0 ) return acc;
    return factorial( n-1, acc * n );
}

} // snip namespace

#endif
