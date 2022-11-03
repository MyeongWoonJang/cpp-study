#ifndef _my_string
#define _my_string

#include <cstring>

template <class CharT>
class my_string
{
public:
    my_string() noexcept;
    my_string(std::size_t, CharT);
    my_string(const my_string&, std::size_t);
    my_string(const my_string&, std::size_t, std::size_t);
    my_string(const CharT*, std::size_t);
    my_string(const CharT*);
    my_string(const my_string&);
    my_string(my_string&&);
    my_string(std::nullptr_t) = delete;
    
private:
}

#include "my_string.inl"

#endif