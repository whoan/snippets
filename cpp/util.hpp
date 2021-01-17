#ifndef _SNIPPETS_CPP_UTIL_HPP
#define _SNIPPETS_CPP_UTIL_HPP

#include <utility>

template <typename Container>
typename Container::const_iterator next(const Container& container, typename std::iterator_traits<typename Container::const_iterator>::difference_type n) {
    return std::next(std::begin(container), n);
}

namespace snip {

template<typename T, T... ints>
std::vector<T> createSequenceImpl(std::integer_sequence<T, ints...>)
{
  return {ints...};
}

template<typename T, T n>
std::vector<T> createSequence()
{
  return createSequenceImpl(std::make_integer_sequence<T, n>{});
}

} // snip namespace

#endif
