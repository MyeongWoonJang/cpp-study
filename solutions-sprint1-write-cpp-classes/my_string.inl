#include "my_string.h"

template <class CharT>
constexpr my_string<CharT>::my_string() noexcept : sz{ 0 }, cap{ 0 }, dat{ nullptr }
{
    
}

template <class CharT>
my_string<CharT>::my_string(std::size_t count, CharT ch) : sz{ count }, cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::fill_n(data(), size(), ch);
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos)
    : sz{ other.size() - debug_check_out_of_range(pos, 0, other.size(), "other.size() < pos") },
    cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(other.data() + pos, other.data() + pos + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos, std::size_t count)
    : sz{ std::min(other.size() - debug_check_out_of_range(pos, 0, other.size(), "other.size() < pos"), count) },
    cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(other.data() + pos, other.data() + pos + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str, std::size_t count)
    : sz{ std::min(_strlen(str), count) }, cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(str, str + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const CharT* str) : sz{ _strlen(str) }, cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(str, str + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other) : sz{ other.sz }, cap{ other.cap }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(other.data(), other.data() + size(), data());
}

template <class CharT>
my_string<CharT>::my_string(my_string&& other) : sz{ 0 }, cap{ 0 }, dat{ nullptr }
{
    this->swap(other);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::operator=(const my_string& other)
{
    this->assign(other);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::operator=(my_string&& other) noexcept
{
    this->assign(std::move(other));
}

template <class CharT>
my_string<CharT>& my_string<CharT>::operator=(const CharT* str)
{
    this->assign(str);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::operator=(CharT ch)
{
    this->assign(&ch, 1);
}

template <class CharT>
void my_string<CharT>::assign(std::size_t count, CharT ch)
{
    my_string tmp{ count, ch };
    this->swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const my_string& str)
{
    my_string tmp{ str };
    this->swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const my_string& str, std::size_t pos, std::size_t count)
{
    my_string tmp{ str, pos, count };
    this->swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(my_string&& str) noexcept
{
    this->swap(str);
}

template <class CharT>
void my_string<CharT>::assign(const CharT* str, std::size_t count)
{
    my_string tmp{ str, count };
    this->swap(tmp);
}

template <class CharT>
void my_string<CharT>::assign(const CharT* str)
{
    my_string tmp{ str };
    this->swap(tmp);
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
constexpr const std::size_t my_string<CharT>::size() const noexcept
{
    return sz;
}

template <class CharT>
constexpr const std::size_t my_string<CharT>::length() const noexcept
{
    return size();
}

template <class CharT>
constexpr const std::size_t my_string<CharT>::capacity() const noexcept
{
    return cap;
}

template <class CharT>
void my_string<CharT>::reserve(std::size_t new_cap)
{
    if (capacity() < new_cap) my_string{ new_cap, *this }.swap(*this);
}

template <class CharT>
void my_string<CharT>::shrink_to_fit()
{
    my_string{ size(), *this }.swap(*this);
}

template <class CharT>
void my_string<CharT>::clear() noexcept
{
    this->_set_sz(0);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, std::size_t count, CharT ch)
{
    this->replace(index, std::size_t{ 0 }, count, ch);
}
    
template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const CharT* str)
{
    // str check
    this->replace(index, std::size_t{ 0 }, str);
}   

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const CharT* str, std::size_t count)
{
    this->replace(index, std::size_t{ 0 }, str, count);
}   

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const my_string& str)
{
    this->replace(index, std::size_t{ 0 }, str);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const my_string& str, std::size_t index_str, std::size_t count = npos)
{
    this->replace(index, std::size_t{ 0 }, str, index_str, count);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const my_string& str)
{
    
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const my_string& str, std::size_t pos_str, std::size_t count_str = npos)
{
    
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const CharT* str, std::size_t count_str)
{
    
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const CharT* str)
{
    
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, std::size_t count_ch, CharT ch)
{
    
}

template <class CharT>
my_string<CharT>& my_string<CharT>::erase(std::size_t index, std::size_t count)
{
    debug_check_out_of_range(index, 0, size(), "index > size()");
    
    if (count == npos) this->clear();
    else if (count) this->_erase(index, std::min(count, size() - index));
    
    return *this;
}

template <class CharT>
void my_string<CharT>::swap(my_string& rhs) noexcept
{
    std::swap(sz, rhs.sz);
    std::swap(cap, rhs.cap);
    std::swap(dat, rhs.cap);
}

template <class CharT>
my_string<CharT>::my_string(std::size_t required_cap, const my_string& other)
    : sz{ std::min(other.sz, required_cap) }, cap{ required_cap }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(other.data(), other.data() + size(), data());
}

template <class CharT>
void my_string<CharT>::_set_sz(std::size_t n)
{
    this->sz = n;
    this->dat[sz] = '\0';
}

template <class CharT>
void my_string<CharT>::_erase(std::size_t index, std::size_t count)
{
    std::copy(&data()[index+count], &data()[size()], &data()[index]);
}

template <class CharT>
constexpr std::size_t my_string<CharT>::_strlen(const CharT* str)
{
    std::size_t ret = -1;
    while (str[++ret] != '\0')
        ;
        
    return ret;
}

namespace
{
    template <class T, class ... Args>
    T* _construct(std::size_t num_of_obj, Args&& ... args)
    {
        return new T[num_of_obj]{ std::forward(args)... };
    }
    
    constexpr std::size_t closest_bin(std::size_t n) noexcept
    {
        std::size_t ret = 2;
        --n;
     
        while (n >>= 1)
            ret <<= 1;
        
        return ret;
    }
}