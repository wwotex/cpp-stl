#pragma once
#include <cassert>

namespace ww {
    template<typename TYPE, size_t SIZE>
    struct array {
        TYPE M_buffer[SIZE] = {};

        [[nodiscard]] constexpr TYPE *begin() noexcept {
            return M_buffer;
        }

        [[nodiscard]] constexpr const TYPE *begin() const noexcept {
            return M_buffer;
        }

        [[nodiscard]] constexpr TYPE *end() noexcept {
            return &M_buffer[SIZE];
        }

        [[nodiscard]] constexpr const TYPE *end() const noexcept {
            return &M_buffer[SIZE];
        }

        [[nodiscard]] constexpr TYPE &back() noexcept {
            static_assert(SIZE > 0);
            return M_buffer[SIZE - 1];
        }

        [[nodiscard]] constexpr const TYPE &back() const noexcept {
            static_assert(SIZE > 0);
            return M_buffer[SIZE - 1];
        }

        [[nodiscard]] constexpr size_t size() noexcept {
            return SIZE;
        }

        [[nodiscard]] constexpr TYPE &operator[](size_t index) {
            assert(index < SIZE);
            return M_buffer[index];
        }

        [[nodiscard]] constexpr const TYPE &operator[](size_t index) const {
            assert(index < SIZE);
            return M_buffer[index];
        }
    };


    template<typename TYPE, typename... ARGS>
    array(TYPE, ARGS...) -> array<std::enable_if_t<(std::is_same_v<TYPE, ARGS> && ...), TYPE>, 1 + sizeof...(ARGS)>;
}
