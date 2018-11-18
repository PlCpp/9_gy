#include <vector>
#include <iostream>
#include <algorithm>

void print(const int& i) {
    std::cout << i << " ";
}

int main() {
    std::vector<int> numbers;
    int i;
    while (std::cin >> i) {
        numbers.push_back(i);
    }

    std::sort(numbers.begin(), numbers.end());

    std::for_each(numbers.begin(), numbers.end(), print);
    /*for (int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }*/
}