#ifndef _SNIPPETS_BINARY_SEARCH_HPP
#define _SNIPPETS_BINARY_SEARCH_HPP

#include <vector>

namespace snip {

template<typename T>
long binarySearch(const vector<T>& collection, int target) {
  int low = 0;
  int high = collection.size()-1;

  for (size_t middle = high/2; low <= high; middle = low + (high-low)/2) {
    if (collection[middle] == target) {
      return middle;
    }
    if (collection[middle] > target) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }
  return -1;
}

} // snip namespace

#endif
