#include <iostream>
#include <map>
#include <algorithm>

void print (const std::pair<char, int>& p) {
    std::cout << p.first << ":" << p.second << '\n';
}

int main() {
    std::map<char, int> chars;
    char ch;
    while (std::cin >> ch) {
        ++chars[ch];
    }

    std::for_each(chars.begin(), chars.end(), print);

    return 0;
}