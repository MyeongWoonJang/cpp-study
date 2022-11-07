#ifndef _my_string
#define _my_string

#include "my_exception.h"
#include <algorithm>

template <class CharT>
class my_string
{
public:
    static constexpr std::size_t npos = -1;

    constexpr my_string() noexcept;
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
    
    constexpr CharT* data() noexcept;
    constexpr const CharT* data() const noexcept;
    constexpr const CharT* c_str() const noexcept;
    
    constexpr std::size_t size() const noexcept;
    constexpr std::size_t length() const noexcept;
    constexpr std::size_t capacity() const noexcept;
    void reserve(std::size_t new_cap);
    void shrink_to_fit();
    
    void clear() noexcept;
    my_string& insert(std::size_t index, std::size_t count, CharT ch);
    my_string& insert(std::size_t index, const CharT* str);
    my_string& insert(std::size_t index, const CharT* str, std::size_t count);
    my_string& insert(std::size_t index, const my_string& str);
    my_string& insert(std::size_t index, const my_string& str, std::size_t index_str, std::size_t count = npos);
    my_string& replace(std::size_t pos, std::size_t count, const my_string& str);
    my_string& replace(std::size_t pos, std::size_t count, const my_string& str, std::size_t pos_str, std::size_t count_str = npos);
    my_string& replace(std::size_t pos, std::size_t count, const CharT* str, std::size_t count_str);
    my_string& replace(std::size_t pos, std::size_t count, const CharT* str);
    my_string& replace(std::size_t pos, std::size_t count, std::size_t count_ch, CharT ch);
    
    my_string& erase(std::size_t index = 0, std::size_t count = npos);  // https://stackoverflow.com/questions/14121064/what-does-c-string-erase-return-this-mean
    
    
    
    void swap(my_string& rhs) noexcept;
    
private:
    my_string(std::size_t cap, const my_string& other);     // for reconstructing operations
    void _set_sz(std::size_t n);
    void _erase(std::size_t index, std::size_t count);

    static constexpr std::size_t _strlen(const CharT* str);

    std::size_t sz;
    std::size_t cap;
    CharT* dat;
};

namespace
{
    template <class T, class ... Args>
    T* _construct(std::size_t num_of_obj, Args&& ... args);
    
    constexpr std::size_t closest_bin(std::size_t n) noexcept;
}

#include "my_string.inl"
#include "undef_macros.inl"

#endif