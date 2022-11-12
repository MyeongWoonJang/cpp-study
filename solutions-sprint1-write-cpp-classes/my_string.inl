#include "my_string.h"

template <class CharT>
constexpr my_string<CharT>::my_string() noexcept : sz{ std::size_t{ 0 } }, cap{ std::size_t{ 0 } }, dat{ nullptr }
{
    
}

template <class CharT>
my_string<CharT>::my_string(std::size_t count, CharT ch) : sz{ count }, cap{ closest_bin(sz) }, dat{ _construct<CharT>(cap, 0) }
{
    std::fill_n(data(), size(), ch);
}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos) : my_string(other, pos, npos)
{

}

template <class CharT>
my_string<CharT>::my_string(const my_string& other, std::size_t pos, std::size_t count)
    : sz{ std::min(other.size() - other._check_i_is_in_size(pos, "other.size() < pos"), count) },
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
my_string<CharT>::my_string(const CharT* str) : my_string(str, npos)
{

}

template <class CharT>
my_string<CharT>::my_string(const my_string& other) : my_string(other, std::size_t{ 0 }, npos)
{

}

template <class CharT>
my_string<CharT>::my_string(my_string&& other) : my_string()
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
    this->assign(str, 0, npos);
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
    this->assign(str, npos);
}

template <class CharT>
constexpr CharT& my_string<CharT>::at(std::size_t pos)
{
    return const_cast<CharT&>(static_cast<const decltype(*this)>(*this).at(pos));
}

template <class CharT>
constexpr const CharT& my_string<CharT>::at(std::size_t pos) const
{
    return this->operator[](debug_check_out_of_range(pos, 0, this->size() - 1, "pos >= size()"));
}

template <class CharT>
constexpr CharT& my_string<CharT>::operator[](std::size_t index)
{
    // The behavior is undefined if index > size() : cppreference
    return const_cast<CharT&>(static_cast<const decltype(*this)>(*this).operator[](index));
}

template <class CharT>
constexpr const CharT& my_string<CharT>::operator[](std::size_t index) const
{
    return this->data()[index];
}

template <class CharT>
constexpr CharT& my_string<CharT>::front()
{
    return const_cast<CharT&>(static_cast<const decltype(*this)>(*this).front());
}

template <class CharT>
constexpr const CharT& my_string<CharT>::front() const
{
    return this->operator[](0);
}

template <class CharT>
constexpr CharT& my_string<CharT>::back()
{
    return const_cast<CharT&>(static_cast<const decltype(*this)>(*this).back());
}

template <class CharT>
constexpr const CharT& my_string<CharT>::back() const
{
    // The behavior is undefined if empty() == true. : cppreference
    return this->operator[](this->size() - 1);
}

template <class CharT>
constexpr CharT* my_string<CharT>::data() noexcept
{
    // Is it really working that const_cast<CharT*> from const CharT*, not CharT* const?
    return const_cast<CharT*>( static_cast<const decltype(*this)>(*this).data() );
}

template <class CharT>
constexpr const CharT* my_string<CharT>::data() const noexcept
{
    return this->dat;
}

template <class CharT>
constexpr const CharT* my_string<CharT>::c_str() const noexcept
{
    return this->data();
}

template <class CharT>
constexpr std::size_t my_string<CharT>::size() const noexcept
{
    return this->sz;
}

template <class CharT>
constexpr std::size_t my_string<CharT>::length() const noexcept
{
    return this->size();
}

template <class CharT>
constexpr std::size_t my_string<CharT>::capacity() const noexcept
{
    return this->cap;
}

template <class CharT>
void my_string<CharT>::reserve(std::size_t new_cap)
{
    if (this->capacity() < new_cap) my_string{ new_cap, *this }.swap(*this);
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
    this->_check_i_is_in_size(index, "index > size()");
    this->replace(index, std::size_t{ 0 }, count, ch);
}
    
template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const CharT* str)
{
    this->insert(index, str, _strlen(str));
}   

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const CharT* str, std::size_t count)
{
    this->_check_i_is_in_size(index, "index > size()");
    this->replace(index, std::size_t{ 0 }, str, count);
}   

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const my_string& str)
{
    this->insert(index, str, std::size_t{ 0 }, str.size());
}

template <class CharT>
my_string<CharT>& my_string<CharT>::insert(std::size_t index, const my_string& str, std::size_t index_str, std::size_t count)
{
    this->_check_i_is_in_size(index, "index > size()");
    str._check_i_is_in_size(index_str, "index_str > str.size()");
    this->replace(index, std::size_t{ 0 }, str, index_str, count);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const my_string& str)
{
    this->replace(pos, count, str, std::size_t{ 0 }, str.size());
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const my_string& str, std::size_t pos_str, std::size_t count_str)
{
    // if count_str == npos or if would extend past str.size(), [pos_str, str.size()) is used to replace.
    this->_check_i_is_in_size(pos, "pos > size()");
    str._check_i_is_in_size(pos_str, "pos_str > str.size()");
    this->_mutate(pos, count, str.data() + pos_str, std::min(count_str, str.size()));
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const CharT* str, std::size_t count_str)
{
    this->_check_i_is_in_size(pos, "pos > size()");
    this->_mutate(pos, count, str, count_str);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, const CharT* str)
{
    this->replace(pos, count, str, _strlen(str));
}

template <class CharT>
my_string<CharT>& my_string<CharT>::replace(std::size_t pos, std::size_t count, std::size_t count_ch, CharT ch)
{
    this->replace(pos, count, my_string{count_ch, ch}, count_ch);
}

template <class CharT>
my_string<CharT>& my_string<CharT>::erase(std::size_t index, std::size_t count)
{
    this->_check_i_is_in_size(index, "index > size()");
    
    if (count == npos) this->clear();
    else if (count) this->_erase(index, std::min(count, this->size() - index));
    
    return *this;
}

template <class CharT>
void my_string<CharT>::swap(my_string& rhs) noexcept
{
    std::swap(this->sz, rhs.sz);
    std::swap(this->cap, rhs.cap);
    std::swap(this->dat, rhs.cap);
}

template <class CharT>
my_string<CharT>::my_string(std::size_t required_cap, const my_string& other)
    : sz{ std::min(other.sz, required_cap) }, cap{ required_cap }, dat{ _construct<CharT>(cap, 0) }
{
    std::copy(other.data(), other.data() + this->size(), this->data());
}

template <class CharT>
void my_string<CharT>::_set_sz(std::size_t n) noexcept
{
    this->sz = n;
    this->dat[sz] = '\0';
}

template <class CharT>
void my_string<CharT>::_erase(std::size_t index, std::size_t count)
{
    std::copy(&data()[index+count], &data()[size()], &data()[index]);
}

/**
 * data in range [this->data() + pos, this->data() + pos + len1]
 * is replaced with [str, str + len2].
 * exception unchecked.
*/
template <class CharT>
void my_string<CharT>::_mutate(std::size_t pos, std::size_t len1, const CharT* str, std::size_t len2)
{
    const std::size_t how_much = this->size() - pos - len1;
    const std::size_t new_sz = this->size() + len2 - len1;
    
    if (new_sz > this->capacity())
    {
        my_string tmp{ closest_bin(new_sz), *this };
        
        if (pos)
            std::copy(this->data(), this->data() + pos, tmp.data());
        if (str && len2)
            std::copy(str, str + len2, tmp.data() + pos);
        if (how_much)
            std::copy(this->data() + pos + len1, this->data() + this->size(), tmp.data() + pos + len2);
            
        this->swap(tmp);
    }
    else
    {
        if (how_much)
            std::move(this->data() + pos + len1, this->data() + this->size(), this->data() + pos + len2);
        if (str && len2)
            std::copy(str, str + len2, this->data() + pos);
        
        _set_sz(new_sz);
    }
}

/**
 * data in range [this->data() + pos, this->data() + pos + len1]
 * is replaced with ch of count.
 * exception unchecked.
*/
template <class CharT>
void _mutate(std::size_t pos, std::size_t len1, CharT ch, std::size_t count)
{
    
}

template <class CharT> template <class YCharT>
decltype(auto) my_string<CharT>::_check_i_is_in_size(std::size_t i, const YCharT* emsg)
{
    return debug_check_out_of_range(i, 0, this->size(), emsg);
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