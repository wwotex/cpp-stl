#include <iostream>
#include "array.hpp"

using std::cout;

int main() {
    ww::array<int, 5> arr{1, 2, 3};
    cout << arr[2] << " " << arr.back() << "\n";

    return 0;
}
