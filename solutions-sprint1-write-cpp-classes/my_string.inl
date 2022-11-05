#include "my_string.h"

template <class CharT>
my_string<CharT>::my_string() noexcept : sz{ 0 }, cap{ 0 }, dat{ nullptr }
{

}

template <class CharT>
my_string<CharT>::my_string(std::size_t count, CharT ch) : sz{ count }, cap{ closest_bin(sz) }, dat{ new CharT[cap]{0} }
{
    std::fill_n(data(), size(), ch);
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos)
    : sz{ subsize(other.size(), pos) }, cap{ closest_bin(sz) }, dat{ new CharT[cap]{0} }
{
    std::copy(other.data() + pos, other.data() + pos + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos, std::size_t count)
    : sz{ std::min(subsize(other.size(), pos), count) }, cap{ closest_bin(sz) }, dat{ new CharT[cap]{0} }
{
    std::copy(other.data() + pos, other.data() + pos + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str, std::size_t count)
    : sz{ std::min(_strlen(str), count) }, cap{ closest_bin(sz) }, dat{ new CharT[cap]{0} }
{
    std::copy(str, str + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str) : sz{ _strlen(str) }, cap{ closest_bin(sz) }, dat{ new CharT[cap]{0} }
{
    std::copy(str, str + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other) : sz{ other.sz }, cap{ other.cap }, dat{ new CharT[cap]{0} }
{
    std::copy(other.data(), other.data() + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(my_string&& other) : sz{ 0 }, cap{ 0 }, dat{ nullptr }
{
    swap(other);
}

template <class CharT>
void my_string<CharT>::assign(std::size_t count, CharT ch)
{
    my_string tmp{ count, ch };
    swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const my_string& str)
{
    my_string tmp{ str };
    swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const my_string& str, std::size_t pos, std::size_t count)
{
    my_string tmp{ str, pos, count };
    swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(my_string&& str) noexcept
{
    swap(str);
}

template <class CharT>
void my_string<CharT>::assign(const CharT* str, std::size_t count)
{
    my_string tmp{ str, count };
    swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const CharT* str)
{
    my_string tmp{ str };
    swap(tmp);
}

template <class CharT>
const std::size_t my_string<CharT>::size() const
{
    return sz;
}

template <class CharT>
const std::size_t my_string<CharT>::length() const
{
    return size();
}

template <class CharT>
void my_string<CharT>::swap(my_string& rhs) noexcept
{
    std::swap(sz, rhs.sz);
    std::swap(cap, rhs.cap);
    std::swap(dat, rhs.cap);
}

template <class CharT>
constexpr CharT* my_string<CharT>::data() noexcept
{
    return dat;
}

template <class CharT>
constexpr const CharT* my_string<CharT>::data() const noexcept
{
    return dat;
}

template <class CharT>
constexpr const CharT* my_string<CharT>::c_str() const noexcept
{
    return data();
}

template <class CharT>
std::size_t my_string<CharT>::_strlen(const CharT* str) noexcept
{
    std::size_t ret = -1;
    while (str[++ret] != '\0')
        ;

    return ret;
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

        while (n >>= 1)
            ret <<= 1;

        return ret;
    }
}