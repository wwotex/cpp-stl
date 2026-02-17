#include <iostream>
#include "array.h"
#include <array>

int main() {
    std::array<int, 5> stdA{};
    ww::array wwA{};
    for (const auto &el: stdA) {
        std::cout << "stdel: " << el << "\n";
    }

    for (const auto &el: wwA) {
        std::cout << "wwel: " << el << "\n";
    }

    std::cout << "Done!" << "\n";

    return 0;
}
