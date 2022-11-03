#ifndef _my_shared_ptr
#define _my_shared_ptr

#include "my_unique_ptr.h"
#include <type_traits>

template <class T>
class my_shared_ptr
{
public:
    constexpr my_shared_ptr() noexcept;
    constexpr my_shared_ptr(std::nullptr_t) noexcept;
    template <class Y>
    explicit my_shared_ptr(Y*);
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

    T* const operator->() const noexcept;
    T& operator*() const noexcept(noexcept(*std::declval<T>()));
    T* const get() const noexcept;
    T& operator[](std::size_t idx) const;
    void swap(my_shared_ptr& rhs) noexcept;
    void reset() noexcept;
    template <class Y>
    void reset(Y* ptr);
    const std::size_t use_count() const noexcept;

    explicit operator bool() const noexcept;

private:
    static std::size_t* make_refs();
    void inc_if_refs_valid() noexcept;

    T* ptr;
    std::size_t* refs;
};

#include "my_shared_ptr.inl"

#endif