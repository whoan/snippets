#include <vector>
#include <string_view>

namespace snip {

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

std::vector<std::string_view> split(std::string_view review, char separator=' ') {
    std::vector<std::string_view> words;
    std::size_t previousPos = review.find_first_not_of(separator);
    for (auto pos = review.find(separator, previousPos); pos != std::string_view::npos; pos = review.find(separator, previousPos)) {
        words.push_back(review.substr(previousPos, pos-previousPos));
        previousPos = review.find_first_not_of(separator, pos + 1);
    }
    if (previousPos != std::string_view::npos) {
        words.push_back(review.substr(previousPos));
    }
    return words;
}

} // snip namespace
