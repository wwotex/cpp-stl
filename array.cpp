//
// Created by gringo on 16/02/2026.
//

#include "array.h"
#include <iostream>

namespace ww {
    array::array() {
        std::cout << "Default constructor" << std::endl;
    }

    int *array::begin() {
        return this->buffer;
    }

    int *array::end() {
        return &this->buffer[ww::array::length];
    }
}
