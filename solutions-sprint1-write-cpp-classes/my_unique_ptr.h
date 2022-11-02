#ifndef _my_unique_ptr
#define _my_unique_ptr

#include <iostream>
#include <type_traits>

template <typename T>
class my_unique_ptr
{
public:
    constexpr my_unique_ptr() noexcept;
    constexpr my_unique_ptr(std::nullptr_t) noexcept;
    explicit my_unique_ptr(T* const ptr) noexcept;
    my_unique_ptr(const my_unique_ptr&) = delete;
    my_unique_ptr(my_unique_ptr&&) noexcept;
    
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;
    my_unique_ptr& operator=(my_unique_ptr&&) noexcept;
    
    ~my_unique_ptr();

    T* const operator->() const noexcept;
    T& operator*() const noexcept(noexcept(*std::declval<T>()));
    T* const get() const noexcept;
    void reset(T* const) noexcept;
    void reset(std::nullptr_t ptr = nullptr) noexcept;
    T* release() noexcept;
    void swap(my_unique_ptr&) noexcept;
    explicit operator bool() const noexcept;

    template <class Y> friend class my_shared_ptr;
private:
    void dealloc() noexcept;
    void invalidate() noexcept;

    T* ptr;
};

template <typename T1, typename T2>
const bool operator==(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T1, typename T2>
const bool operator!=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T1, typename T2>
const bool operator>(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T1, typename T2>
const bool operator<(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T1, typename T2>
const bool operator>=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T1, typename T2>
const bool operator<=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept;

template <typename T>
const bool operator==(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator==(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <typename T>
const bool operator!=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator!=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <typename T>
const bool operator>(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator>(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <typename T>
const bool operator<(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator<(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <typename T>
const bool operator>=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator>=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <typename T>
const bool operator<=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <typename T>
const bool operator<=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept;

template <class T>
std::ostream& operator<<(std::ostream& os, const my_unique_ptr<T>& rhs);

#include "my_unique_ptr.inl"

#endif