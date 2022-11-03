#include "my_string.h"

template <class CharT>
my_string<CharT>::my_string() noexcept : cap{ 0 }, sz{ 0 }, dat{ nullptr }
{
    
}

template <class CharT>
my_string<CharT>::my_string(std::size_t count, CharT ch) : cap{ closest_bin(count) }, sz{ count }, dat{ new CharT[cap] }
{
    while(--count)
        dat[count] = ch;
}

// 여기서부터 작성해야 함

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos)
{
    
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos, std::size_t count)
{
    
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str, std::size_t count)
{
    
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str)
{
    
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other)
{
    
}

template <class CharT>
my_string<CharT>::my_string(my_string&& other)
{
    
}

namespace
{
    constexpr std::size_t closest_bin(std::size_t n)
    {
        std::size_t ret = 2;
        --n;
     
        while(n >>= 1)
            ret <<= 1;
        
        return ret;
    }
}