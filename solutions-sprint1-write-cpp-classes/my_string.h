#ifndef _my_string
#define _my_string

#include <cstring>

template <class CharT>
class my_string
{
public:
    my_string() noexcept;
    my_string(std::size_t count, CharT ch);
    my_string(const my_string& other, std::size_t pos);
    my_string(const my_string& other, std::size_t pos, std::size_t count);
    my_string(const CharT* str, std::size_t count);
    my_string(const CharT* str);
    my_string(const my_string& other);
    my_string(my_string&& other);
    my_string(std::nullptr_t) = delete;
    
private:
    std::size_t cap;
    std::size_t sz;
    CharT* dat;
};

namespace
{
    constexpr std::size_t closest_bin(std::size_t n);
}

#include "my_string.inl"

#endif