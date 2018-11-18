#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

typedef std::istream_iterator<int> int_iterator;
typedef std::ostream_iterator<int> int_out_iterator;

int main() {

    std::multiset<int> numbers(int_iterator(std::cin), int_iterator());
    std::copy(numbers.begin(), numbers.end(), int_out_iterator(std::cout, " "));
}