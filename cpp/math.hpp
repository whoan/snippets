#include <cmath>

namespace snip {

// double is necessary to not lose precision
double log10(long input) {
  return std::log(input) / std::log(10);
}

int getMostSignificantDigit(int x) {
  return x / std::pow(10, int(snip::log10(x)));
}

int getLeastSignificantDigit(int x) {
  return x % 10;
}

} // snip namespace
