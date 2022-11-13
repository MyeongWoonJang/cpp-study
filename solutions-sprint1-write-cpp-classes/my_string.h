#ifndef _my_string
#define _my_string

#include "my_exception.h"
#include <algorithm>

#define _check_i_is_in_size(i, strobj, emsg) debug_check_out_of_range((i), std::size_t{ 0 }, (strobj).size(), (emsg))

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
    
    [[nodiscard]] constexpr CharT& at(std::size_t pos);
    [[nodiscard]] constexpr const CharT& at(std::size_t pos) const;
    [[nodiscard]] constexpr CharT& operator[](std::size_t index);
    [[nodiscard]] constexpr const CharT& operator[](std::size_t index) const;
    [[nodiscard]] constexpr CharT& front();
    [[nodiscard]] constexpr const CharT& front() const;
    [[nodiscard]] constexpr CharT& back();
    [[nodiscard]] constexpr const CharT& back() const;
    [[nodiscard]] constexpr CharT* data() noexcept;
    [[nodiscard]] constexpr const CharT* data() const noexcept;
    [[nodiscard]] constexpr const CharT* c_str() const noexcept;
    
    [[nodiscard]] constexpr bool empty() const noexcept;
    [[nodiscard]] constexpr std::size_t size() const noexcept;
    [[nodiscard]] constexpr std::size_t length() const noexcept;
    [[nodiscard]] constexpr std::size_t capacity() const noexcept;
    void reserve(std::size_t new_cap);
    void resize(std::size_t n);
    void resize(std::size_t n, CharT ch);
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
    void push_back(CharT ch);
    void pop_back();
    my_string& append(std::size_t count, CharT ch);
    my_string& append(const my_string& str);
    my_string& append(const my_string& str, std::size_t pos, std::size_t count = npos);
    my_string& append(const CharT* str);
    my_string& append(const CharT* str, std::size_t count);
    my_string& erase(std::size_t index = 0, std::size_t count = npos);  // https://stackoverflow.com/questions/14121064/what-does-c-string-erase-return-this-mean
    [[nodiscard]] constexpr int compare(const my_string& str) const noexcept;
    [[nodiscard]] constexpr int compare(std::size_t pos, std::size_t count, const my_string& str) const;
    [[nodiscard]] constexpr int compare(std::size_t pos1, std::size_t count1, const my_string& str, std::size_t pos2, std::size_t count2 = npos) const;
    [[nodiscard]] constexpr int compare(const CharT* str) const;
    [[nodiscard]] constexpr int compare(std::size_t pos, std::size_t count, const CharT* str) const;
    [[nodiscard]] constexpr int compare(std::size_t pos, std::size_t count1, const CharT* str, std::size_t count2) const;
    [[nodiscard]] constexpr my_string substr(std::size_t pos = 0, std::size_t count = npos) const;
    
    [[nodiscard]] constexpr std::size_t find(const my_string& str, std::size_t pos = 0) const noexcept;
    [[nodiscard]] constexpr std::size_t find(const CharT* str, std::size_t pos = 0) const;
    [[nodiscard]] constexpr std::size_t find(const CharT* str, std::size_t pos, std::size_t count) const;
    [[nodiscard]] constexpr std::size_t find(CharT ch, std::size_t pos = 0) const noexcept;
    
    void swap(my_string& rhs) noexcept;
    
private:
    my_string(std::size_t cap, const my_string& other);     // for reconstructing operations
    void _set_sz(std::size_t n) noexcept;
    void _mutate(std::size_t pos, std::size_t len1, const CharT* str, std::size_t len2);
    void _mutate(std::size_t pos, std::size_t len1, CharT ch, std::size_t count);

    std::size_t sz;
    std::size_t cap;
    CharT* dat;
};

template <class CharT>
constexpr my_string<CharT> operator+(const my_string<CharT>& lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr my_string<CharT> operator+(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(const my_string<CharT>& lhs, CharT rhs);

template <class CharT>
constexpr my_string<CharT> operator+(CharT lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(my_string<CharT>&& lhs, my_string<CharT>&& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(my_string<CharT>&& lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(const my_string<CharT>& lhs, my_string<CharT>&& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(my_string<CharT>&& lhs, const CharT* rhs);

template <class CharT>
constexpr my_string<CharT> operator+(const CharT* lhs, my_string<CharT>&& rhs);

template <class CharT>
constexpr my_string<CharT> operator+(my_string<CharT>&& lhs, CharT rhs);

template <class CharT>
constexpr my_string<CharT> operator+(CharT lhs, my_string<CharT>&& rhs);

template <class CharT>
constexpr bool operator==(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator==(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator==(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr bool operator!=(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator!=(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator!=(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr bool operator<(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator<(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator<(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr bool operator>(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator>(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator>(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr bool operator<=(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator<=(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator<=(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr bool operator>=(const my_string<CharT>& lhs, const my_string<CharT>& rhs) noexcept;

template <class CharT>
constexpr bool operator>=(const CharT* lhs, const my_string<CharT>& rhs);

template <class CharT>
constexpr bool operator>=(const my_string<CharT>& lhs, const CharT* rhs);

template <class CharT>
constexpr std::size_t _strlen(const CharT* str);

template <class CharT>
constexpr int _strncmp(const CharT* lhs, const CharT* rhs, std::size_t len);

template <class CharT>
my_string<CharT> __str_concat(const CharT* lhs, std::size_t len1, const CharT* rhs, std::size_t len2);

template <class T, class ... Args>
T* _construct(std::size_t num_of_obj, Args&& ... args);
    
constexpr std::size_t closest_bin(std::size_t n) noexcept;

#include "my_string.inl"

#endif