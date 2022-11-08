#include "my_shared_ptr.h"

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr() noexcept : ptr{ nullptr }, refs{ nullptr }
{
    
}

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr(std::nullptr_t) noexcept : ptr{ nullptr }, refs{ nullptr }
{
    
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(Y* ptr) : ptr{ ptr }, refs{ make_refs() }
{
    
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& other) noexcept : ptr{ other.get() }, refs{ other.refs }
{
    inc_if_refs_valid();
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<Y>& other) noexcept : ptr{ static_cast<T*>(other.get()) }, refs{ other.refs }
{
    inc_if_refs_valid();
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr&& other) noexcept : ptr{ nullptr }, refs{ nullptr }
{
    swap(other);
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr<Y>&& other) noexcept : ptr{ nullptr }, refs{ nullptr }
{
    swap(static_cast<my_shared_ptr<T>>(other));
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_unique_ptr<Y>&& other) : ptr{ static_cast<T*>(other.release()) }, refs{ make_refs() }
{
    
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr& other) noexcept
{
    my_shared_ptr tmp{ other };
    swap(tmp);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr<Y>& other) noexcept
{
    my_shared_ptr tmp{ other };
    swap(tmp);
    
    return *this;
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr&& other) noexcept
{
    swap(other);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr<Y>&& other) noexcept
{
    swap(other);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_unique_ptr<Y>&& other)
{
    my_shared_ptr tmp{ other };
    swap(tmp);
    
    return *this;
}

template <class T>
my_shared_ptr<T>::~my_shared_ptr() noexcept
{
    if (refs)
        if (!--*refs)
        {
            delete refs;
            delete ptr;
        }
}

template <class T>
T* const my_shared_ptr<T>::operator->() const noexcept
{
    return ptr;
}

template <class T>
T& my_shared_ptr<T>::operator*() const noexcept(noexcept(*std::declval<T>()))
{
    return *ptr;
}

template <class T>
T* const my_shared_ptr<T>::get() const noexcept
{
    return operator->();
}

template <class T>
T& my_shared_ptr<T>::operator[](std::size_t idx) const
{
    return get()[idx];
}

template <class T>
void my_shared_ptr<T>::swap(my_shared_ptr& rhs) noexcept
{
    std::swap(ptr, rhs.ptr);
    std::swap(refs, rhs.refs);
}

template <class T>
void my_shared_ptr<T>::reset() noexcept
{
    my_shared_ptr{}.swap(*this);    
}

template <class T> template <class Y>
void my_shared_ptr<T>::reset(Y* ptr)
{
    my_shared_ptr{ ptr }.swap(*this);
}

template <class T>
std::size_t my_shared_ptr<T>::use_count() const noexcept
{
    if (refs) return *refs;
    else return 0;
}

template <class T>
my_shared_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(ptr);
}

template <class T>
std::size_t* my_shared_ptr<T>::make_refs()
{
    return new std::size_t{ 1 };
}

template <class T>
void my_shared_ptr<T>::inc_if_refs_valid() noexcept
{
    if (refs) ++*refs;
}