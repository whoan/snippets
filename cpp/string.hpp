#ifndef _SNIPPETS_CPP_STRING_HPP
#define _SNIPPETS_CPP_STRING_HPP

#include <vector>
#include <string_view>
#include <charconv>

namespace snip {

int sviewtoi(string_view input) {
    // notice that it is not checking for errors: https://en.cppreference.com/w/cpp/utility/from_chars
    int output = 0;
    std::from_chars(input.data(), input.data() + input.size(), output);
    return output;
}

// unsing a forwarding reference makes it possibe to pass by value or reference (rvalue)
template<typename String>
String trim(String&& input, char toTrim=' ') {
    // remvove trailing characters
    while (input.size() && input.back() == toTrim) {
        input.resize(input.size()-1);
    }

    // remove leading characters
    auto pos = input.find_first_not_of(toTrim);
    if (pos != 0) {
        input = input.substr(pos);
    }
    return input;
}

std::vector<std::string_view> split(std::string_view input, char separator=' ') {
    std::vector<std::string_view> words;
    std::size_t previousPos = input.find_first_not_of(separator);
    for (auto pos = input.find(separator, previousPos); pos != std::string_view::npos; pos = input.find(separator, previousPos)) {
        words.push_back(input.substr(previousPos, pos-previousPos));
        previousPos = input.find_first_not_of(separator, pos + 1);
    }
    if (previousPos != std::string_view::npos) {
        words.push_back(input.substr(previousPos));
    }
    return words;
}

} // snip namespace

#endif
