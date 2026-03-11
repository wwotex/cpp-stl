#include <iostream>
#include <array>
#include <deque>
#include <vector>

#include "array.hpp"
#include "vector.hpp"

using std::cout;

int main() {
    {
        ww::vector<std::string> vec;
        for (int i = 0; i < 10; i++) {
            vec.push_back("xar");
            if (i > 0) {
                vec[i / 2] = "CHANGED";
            }
            for (const auto &el: vec) {
                cout << el << ", ";
            }
            cout << "\n";
            cout << "size: " << vec.size() << " capacity: " << vec.capacity() << "\n\n";
        }
    }
    {
        ww::vector<int> vec;
        for (int i = 0; i < 5; i++) {
            vec.push_back(i * 10);
        }
        for (int i = 0; i < 5; i++) {
            vec.pop_back();
            vec.shrink_to_fit();
            cout << "size: " << vec.size() << " capacity: " << vec.capacity() << "\n\n";
        }
    }
    return 0;
}
