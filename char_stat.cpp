#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

typedef std::istream_iterator<char> char_iterator;

int main() {
    std::multiset<char> chars(
        char_iterator(std::cin),
        char_iterator()
    );

    for (std::multiset<char>::iterator it = chars.begin(); it != chars.end();) {
        std::cout << *it << ":" << chars.count(*it) << '\n';
        //it++;
        it = chars.upper_bound(*it);
    }

    return 0;
}