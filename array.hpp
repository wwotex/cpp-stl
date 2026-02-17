#pragma once

namespace ww {
    template<typename TYPE, size_t SIZE>
    class array {
        TYPE buffer[SIZE];

    public:
        array() : buffer{} {
            std::cout << "Default constructor" << std::endl;
        }

        [[nodiscard]] TYPE *begin() {
            return this->buffer;
        }

        [[nodiscard]] const TYPE *begin() const {
            return this->buffer;
        }

        [[nodiscard]] TYPE *end() {
            return &this->buffer[SIZE];
        }

        [[nodiscard]] const TYPE *end() const {
            return &this->buffer[SIZE];
        }

        [[nodiscard]] constexpr size_t size() const {
            return SIZE;
        }

        [[nodiscard]] TYPE &operator[](size_t index) {
            return this->buffer[index];
        }

        [[nodiscard]] const TYPE &operator[](size_t index) const {
            return this->buffer[index];
        }
    };
}
