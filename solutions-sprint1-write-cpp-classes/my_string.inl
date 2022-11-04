#include "my_string.h"

template <class CharT>
my_string<CharT>::my_string() noexcept : sz{ 0 }, cap{ 0 }, dat{ nullptr }
{
    
}

template <class CharT>
my_string<CharT>::my_string(std::size_t count, CharT ch) : sz{ count }, cap{ closest_bin(sz) }, dat{ new CharT[cap] }
{

}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos)
    : sz{ subsize(other.size(), pos) }, cap{ closest_bin(sz) }, dat{ new CharT[cap] }
{

}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos, std::size_t count)
    : sz{ std::min( subsize(other.size(), pos), count ) }, cap{ closest_bin(sz) }, dat{ new CharT[cap] }
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
    constexpr std::size_t subsize(std::size_t src_size, std::size_t pos)
    {
        return pos < src_size ? src_size - pos : 0;
    }
    
    constexpr std::size_t closest_bin(std::size_t n)
    {
        std::size_t ret = 2;
        --n;
     
        while(n >>= 1)
            ret <<= 1;
        
        return ret;
    }
}