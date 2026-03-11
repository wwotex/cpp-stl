#pragma once
#include <cassert>

namespace ww {
    template<typename TYPE>
    class vector {
        TYPE *m_buffer = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;

        void _reallocate_buffer(size_t new_capacity) {
            auto old_buffer = m_buffer;
            m_buffer = new TYPE[new_capacity];
            m_capacity = new_capacity;


            if (old_buffer == nullptr) {
                return;
            }

            auto n_to_copy = std::min(new_capacity, m_size);
            for (size_t i = 0; i < n_to_copy; i++) {
                m_buffer[i] = old_buffer[i];
            }

            delete[] old_buffer;
        }

    public:
        void clear() noexcept {
            delete[] m_buffer;
            m_buffer = nullptr;
            m_size = 0;
            m_capacity = 0;
        }

        void push_back(const TYPE &new_element) noexcept {
            if (m_size == m_capacity) {
                this->reserve(m_capacity == 0 ? 1 : m_capacity * 2);
            }
            m_buffer[m_size] = new_element;
            m_size++;
        }

        void pop_back() noexcept {
            assert(m_size > 0);
            m_size--;
        }

        void shrink_to_fit() noexcept {
            if (m_capacity == m_size) {
                return;
            }

            this->_reallocate_buffer(m_size);
        }

        void reserve(const size_t new_capacity) noexcept {
            if (m_capacity >= new_capacity) {
                return;
            }
            this->_reallocate_buffer(new_capacity);
        }

        [[nodiscard]] constexpr TYPE &operator[](size_t index) noexcept {
            assert(index < m_size);
            return m_buffer[index];
        }

        [[nodiscard]] constexpr const TYPE &operator[](size_t index) const noexcept {
            assert(index < m_size);
            return m_buffer[index];
        }

        [[nodiscard]] constexpr size_t size() const noexcept {
            return m_size;
        }

        [[nodiscard]] constexpr size_t capacity() const noexcept {
            return m_capacity;
        }

        [[nodiscard]] constexpr TYPE *begin() noexcept {
            return m_buffer;
        }

        [[nodiscard]] constexpr const TYPE *begin() const noexcept {
            return m_buffer;
        }

        [[nodiscard]] constexpr TYPE *end() noexcept {
            return m_buffer + m_size;
        }

        [[nodiscard]] constexpr const TYPE *end() const noexcept {
            return m_buffer + m_size;
        }
    };
}
