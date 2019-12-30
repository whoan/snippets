#include <cmath>

namespace snip {

// double is necessary to not lose precision
double log10(long input) {
    return std::log(input) / std::log(10);
}

} // snip namespace
