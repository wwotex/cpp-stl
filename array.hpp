#pragma once
#include <cassert>

namespace ww {
    template<typename TYPE, size_t SIZE>
    struct array {
        TYPE M_buffer[SIZE] = {};

        [[nodiscard]] TYPE *begin() {
            return M_buffer;
        }

        [[nodiscard]] const TYPE *begin() const {
            return M_buffer;
        }

        [[nodiscard]] TYPE *end() {
            return &M_buffer[SIZE];
        }

        [[nodiscard]] const TYPE *end() const {
            return &M_buffer[SIZE];
        }

        [[nodiscard]] constexpr size_t size() const {
            return SIZE;
        }

        [[nodiscard]] constexpr TYPE &operator[](size_t index) {
            assert(index < SIZE);
            return M_buffer[index];
        }

        [[nodiscard]] constexpr const TYPE &operator[](size_t index) const {
            assert(("Index out of range", index < SIZE));
            return M_buffer[index];
        }
    };


    template<typename TYPE, typename... ARGS>
    array(TYPE, ARGS...) -> array<std::enable_if_t<(std::is_same_v<TYPE, ARGS> && ...), TYPE>, 1 + sizeof...(ARGS)>;
}
