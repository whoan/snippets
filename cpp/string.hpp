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

std::vector<std::string_view> split(std::string_view input) const {
    std::vector<std::string_view> tokens;
    std:size_t start = 0;
    for (auto pos = input.find(separator); pos != std::string_view::npos; pos = input.find(separator, start)) {
        tokens.push_back(input.substr(start, pos-start));
        start = pos + 1;
    }
    tokens.push_back(input.substr(start));
    return tokens;
}

} // snip namespace

#endif
