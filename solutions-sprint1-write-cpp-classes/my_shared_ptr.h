#ifndef _my_shared_ptr
#define _my_shared_ptr

#include "my_unique_ptr.h"

#include <iostream>
#include <type_traits>

template <class T>
class my_shared_ptr
{
public:
    constexpr my_shared_ptr() noexcept;
    constexpr my_shared_ptr(std::nullptr_t) noexcept;
    template <class Y>
    explicit my_shared_ptr(Y* ptr);
    my_shared_ptr(const my_shared_ptr& other) noexcept;
    template <class Y>
    my_shared_ptr(const my_shared_ptr<Y>& other) noexcept;
    my_shared_ptr(my_shared_ptr&& other) noexcept;
    template <class Y>
    my_shared_ptr(my_shared_ptr<Y>&& other) noexcept;
    template <class Y>
    my_shared_ptr(my_unique_ptr<Y>&& other);

    my_shared_ptr& operator=(const my_shared_ptr& other) noexcept;
    template <class Y>
    my_shared_ptr& operator=(const my_shared_ptr<Y>& other) noexcept;
    my_shared_ptr& operator=(my_shared_ptr&& other) noexcept;
    template <class Y>
    my_shared_ptr& operator=(my_shared_ptr<Y>&& other) noexcept;
    template <class Y>
    my_shared_ptr& operator=(my_unique_ptr<Y>&& other);
    
    ~my_shared_ptr() noexcept;
    
    [[nodiscard]] T* const operator->() const noexcept;
    [[nodiscard]] T& operator*() const noexcept(noexcept(*std::declval<T>()));
    [[nodiscard]] T* const get() const noexcept;
    [[nodiscard]] T& operator[](std::size_t idx) const;
    void swap(my_shared_ptr& rhs) noexcept;
    void reset() noexcept;
    template <class Y>
    void reset(Y* ptr);
    [[nodiscard]] std::size_t use_count() const noexcept;
    
    [[nodiscard]] explicit operator bool() const noexcept;

private:
    static std::size_t* make_refs();
    void inc_if_refs_valid() noexcept;

    T* ptr;
    std::size_t* refs;
};

template <class T1, class T2>
const bool operator==(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
const bool operator!=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
const bool operator>(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
const bool operator<(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
const bool operator>=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T1, class T2>
const bool operator<=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept;

template <class T>
const bool operator==(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator==(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
const bool operator!=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator!=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
const bool operator>(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator>(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
const bool operator<(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator<(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
const bool operator>=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator>=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
const bool operator<=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept;

template <class T>
const bool operator<=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept;

template <class T>
std::ostream& operator<<(std::ostream& os, const my_shared_ptr<T>& rhs);

#include "my_shared_ptr.inl"

#endif