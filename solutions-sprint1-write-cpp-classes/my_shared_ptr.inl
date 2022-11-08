#include "my_shared_ptr.h"

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr() noexcept : ptr{ nullptr }, refs{ nullptr }
{
    
}

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr(std::nullptr_t) noexcept : my_shared_ptr()
{
    
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(Y* ptr) : ptr{ ptr }, refs{ make_refs() }
{
    
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& other) noexcept : ptr{ other.get() }, refs{ other.refs }
{
    this->inc_if_refs_valid();
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<Y>& other) noexcept : ptr{ other.get() }, refs{ other.refs }
{
    this->inc_if_refs_valid();
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr&& other) noexcept : ptr{ nullptr }, refs{ nullptr }
{
    this->swap(other);
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr<Y>&& other) noexcept : ptr{ other.get() }, refs{ nullptr }
{
    std::swap(refs, other.refs);
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_unique_ptr<Y>&& other) : ptr{ other.release() }, refs{ make_refs() }
{
    
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr& other) noexcept
{
    my_shared_ptr tmp{ other };
    this->swap(tmp);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr<Y>& other) noexcept
{
    my_shared_ptr tmp{ other };
    this->swap(tmp);
    
    return *this;
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr&& other) noexcept
{
    this->swap(other);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr<Y>&& other) noexcept
{
    this->swap(other);
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_unique_ptr<Y>&& other)
{
    my_shared_ptr tmp{ other };
    this->swap(tmp);
    
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
    return this->get()[idx];
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

template <class T1, class T2>
const bool operator==(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template <class T1, class T2>
const bool operator!=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return lhs.get() != rhs.get();
}

template <class T1, class T2>
const bool operator<(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return std::less<std::common_type_t<T1*, T2*>>{}(lhs.get(), rhs.get());
}

template <class T1, class T2>
const bool operator>(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return rhs < lhs;
}

template <class T1, class T2>
const bool operator<=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return !(rhs < lhs);
}

template <class T1, class T2>
const bool operator>=(const my_shared_ptr<T1>& lhs, const my_shared_ptr<T2>& rhs) noexcept
{
    return !(lhs < rhs);
}

template <class T>
const bool operator==(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !lhs;
}

template <class T>
const bool operator==(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return !rhs;
}

template <class T>
const bool operator!=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return (bool)lhs;
}

template <class T>
const bool operator!=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return (bool)rhs;
}

template <class T>
const bool operator<(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return std::less<T*>{}(lhs.get(), nullptr);
}

template <class T>
const bool operator<(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return std::less<T*>{}(nullptr, rhs.get());
}

template <class T>
const bool operator>(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return nullptr < lhs;
}

template <class T>
const bool operator>(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return rhs < nullptr;
}

template <class T>
const bool operator<=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !(nullptr < lhs);
}

template <class T>
const bool operator<=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return !(rhs < nullptr);
}

template <class T>
const bool operator>=(const my_shared_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !(lhs < nullptr);
}

template <class T>
const bool operator>=(std::nullptr_t lhs, const my_shared_ptr<T>& rhs) noexcept
{
    return !(nullptr < rhs);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const my_shared_ptr<T>& rhs)
{
    os << rhs.get();
    return os;
}