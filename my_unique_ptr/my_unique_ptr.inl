#include "my_unique_ptr.h"

template <typename T>
constexpr my_unique_ptr<T>::my_unique_ptr() noexcept : ptr{nullptr}
{
    
}

template <typename T>
constexpr my_unique_ptr<T>::my_unique_ptr(std::nullptr_t) noexcept : ptr{nullptr}
{
    
}

template <typename T>
my_unique_ptr<T>::my_unique_ptr(T* const ptr) noexcept : ptr{ptr}
{
    
}

template <typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr&& other) noexcept : ptr{other.ptr}
{
    other.ptr = nullptr;
}

template <typename T>
my_unique_ptr<T>& my_unique_ptr<T>::operator=(my_unique_ptr&& other) noexcept
{
    if (this != &other)
    {
        reset(other.ptr);
        other.ptr = nullptr;
    }
    
    return *this;
}

template <typename T>
my_unique_ptr<T>::~my_unique_ptr()
{
    reset();
}

template <typename T>
T* const my_unique_ptr<T>::operator->() noexcept
{
    return ptr;
}

template <typename T>
const T* const my_unique_ptr<T>::operator->() const noexcept
{
    return ptr;
}

template <typename T>
T& my_unique_ptr<T>::operator*() noexcept
{
    return *ptr;
}

template <typename T>
const T& my_unique_ptr<T>::operator*() const noexcept(noexcept(*std::declval<T>()))
{
    return *ptr;
}

template <typename T>
T* const my_unique_ptr<T>::get() noexcept
{
    return operator->();
}

template <typename T>
const T* const my_unique_ptr<T>::get() const noexcept
{
    return operator->();
}

template <typename T>
void my_unique_ptr<T>::reset(T* const ptr) noexcept
{
    if (this->ptr) delete this->ptr;
    this->ptr = ptr;
}

template <typename T>
void my_unique_ptr<T>::reset(std::nullptr_t) noexcept
{
    if (this->ptr) delete this->ptr;
    this->ptr = nullptr;
}

template <typename T>
T* my_unique_ptr<T>::release() noexcept
{
    reset(nullptr);
    return ptr;
}

template <typename T>
void my_unique_ptr<T>::swap(my_unique_ptr& other) noexcept
{
    std::swap(ptr, other.ptr);
}

template <typename T>
my_unique_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(ptr);
}

template <typename T1, typename T2>
const bool operator==(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template <typename T1, typename T2>
const bool operator!=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return lhs.get() != rhs.get();
}

template <typename T1, typename T2>
const bool operator<(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return std::less<std::common_type_t<T1*, T2*>>{}(lhs.get(), rhs.get());
}

template <typename T1, typename T2>
const bool operator>(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return rhs < lhs;
}

template <typename T1, typename T2>
const bool operator<=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return !(rhs < lhs);
}

template <typename T1, typename T2>
const bool operator>=(const my_unique_ptr<T1>& lhs, const my_unique_ptr<T2>& rhs) noexcept
{
    return !(lhs < rhs);
}

template <typename T>
const bool operator==(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !lhs;
}

template <typename T>
const bool operator==(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return !rhs;
}

template <typename T>
const bool operator!=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return (bool)lhs;
}

template <typename T>
const bool operator!=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return (bool)rhs;
}

template <typename T>
const bool operator<(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return std::less<T*>{}(lhs.get(), nullptr);
}

template <typename T>
const bool operator<(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return std::less<T*>{}(nullptr, rhs.get());
}

template <typename T>
const bool operator>(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return nullptr < lhs;
}

template <typename T>
const bool operator>(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return rhs < nullptr;
}

template <typename T>
const bool operator<=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !(nullptr < lhs);
}

template <typename T>
const bool operator<=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return !(rhs < nullptr);
}

template <typename T>
const bool operator>=(const my_unique_ptr<T>& lhs, std::nullptr_t rhs) noexcept
{
    return !(lhs < nullptr);
}

template <typename T>
const bool operator>=(std::nullptr_t lhs, const my_unique_ptr<T>& rhs) noexcept
{
    return !(nullptr < rhs);
}