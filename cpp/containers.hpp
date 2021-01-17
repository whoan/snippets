#ifndef _SNIPPETS_CONTAINERS_HPP
#define _SNIPPETS_CONTAINERS_HPP

#include <algorithm>

namespace snip {

template<typename Collection>
Collection duplicateAndMerge(Collection collection) {
  collection.resize(collection.size()*2);
  std::copy_backward(std::begin(collection), std::next(std::begin(collection), collection.size()/2), std::end(collection));
  return collection;
}

} // snip namespace

#endif
