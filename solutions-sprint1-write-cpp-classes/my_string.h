#ifndef _my_string
#define _my_string

#include <algorithm>

template <class CharT>
class my_string
{
public:
    static constexpr std::size_t npos = -1;

    my_string() noexcept;
    my_string(std::size_t count, CharT ch);
    my_string(const my_string& other, std::size_t pos);
    my_string(const my_string& other, std::size_t pos, std::size_t count);
    my_string(const CharT* str, std::size_t count);
    my_string(const CharT* str);
    my_string(const my_string& other);
    my_string(my_string&& other);
    my_string(std::nullptr_t) = delete;

    my_string& operator=(const my_string& other);
    my_string& operator=(my_string&& other) noexcept;
    my_string& operator=(const CharT* str);
    my_string& operator=(CharT ch);

    void assign(std::size_t count, CharT ch);
    void assign(const my_string& str);
    void assign(const my_string& str, std::size_t pos, std::size_t count = npos);
    void assign(my_string&& str) noexcept;
    void assign(const CharT* str, std::size_t count);
    void assign(const CharT* str);

    const std::size_t size() const noexcept;
    const std::size_t length() const noexcept;

    void swap(my_string& rhs) noexcept;

    constexpr CharT* data() noexcept;
    constexpr const CharT* data() const noexcept;
    constexpr const CharT* c_str() const noexcept;

private:
    static constexpr std::size_t _strlen(const CharT* str);

    std::size_t sz;
    std::size_t cap;
    CharT* dat;
};

namespace
{
    constexpr std::size_t subsize(std::size_t src_size, std::size_t pos) noexcept;
    constexpr std::size_t closest_bin(std::size_t n) noexcept;
}

#include "my_string.inl"

#endif