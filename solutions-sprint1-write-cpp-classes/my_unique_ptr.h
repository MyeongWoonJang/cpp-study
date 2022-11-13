#ifndef _my_unique_ptr
#define _my_unique_ptr

#include <iostream>
#include <type_traits>

template <class T>
class my_unique_ptr
{
public:
    constexpr my_unique_ptr() noexcept;
    constexpr my_unique_ptr(std::nullptr_t) noexcept;
    explicit my_unique_ptr(T* ptr) noexcept;
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr(my_unique_ptr&& other) noexcept;
    
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(my_unique_ptr&& other) noexcept;
    
    ~my_unique_ptr();

    [[nodiscard]] T* const operator->() const noexcept;
    [[nodiscard]] T& operator*() const noexcept(noexcept(*std::declval<T>()));
    [[nodiscard]] T* const get() const noexcept;
    [[nodiscard]] T& operator[](std::size_t idx) const;
    void reset(T* ptr) noexcept;
    void reset(std::nullptr_t ptr = nullptr) noexcept;
    [[nodiscard]] T* release() noexcept;
    void swap(my_unique_ptr& rhs) noexcept;
    [[nodiscard]] explicit operator bool() const noexcept;
    
private:
    T* ptr;
};

template <class T1, class T2>
[[nodiscard]] const bool operator==(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
[[nodiscard]] const bool operator!=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
[[nodiscard]] const bool operator>(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
[[nodiscard]] const bool operator<(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
[[nodiscard]] const bool operator>=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
[[nodiscard]] const bool operator<=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator==(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator==(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator!=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator!=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator>(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator>(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator<(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator<(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator>=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator>=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator<=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
[[nodiscard]] const bool operator<=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
std::ostream& operator<<(std::ostream& os, const my_unique_ptr<T>& rhs);

#include "my_unique_ptr.inl"

#endif