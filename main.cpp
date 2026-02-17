#include <iostream>
#include "array.hpp"
#include <array>

int main() {
    // std::array<int, 5> my_array{};
    // my_array.size();

    ww::array<int, 10> wwA{};

    for (const auto &el: wwA) {
        std::cout << el << ", ";
    }

    for (int i = 0; i < wwA.size(); i++) {
        wwA[i] = (i + 5) % 10;
    }

    std::cout << "\n";
    for (int i = 0; i < wwA.size(); i++) {
        std::cout << wwA[i] << ", ";
    }

    std::cout << "\nDone!\n";

    return 0;
}
