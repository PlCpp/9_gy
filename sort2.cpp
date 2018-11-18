#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

void print(const int& i) {
    std::cout << i << " ";
}

int main() {
    std::vector<int> numbers(
        std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>()
    );

    std::sort(numbers.begin(), numbers.end());

    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
}