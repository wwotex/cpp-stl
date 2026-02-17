#pragma once
#include <cstdlib>

namespace ww {
    class array {
        static constexpr size_t length = 5;
        int buffer[length]{};

    public:
        array();

        int *begin();
        int *end();
    };
}
