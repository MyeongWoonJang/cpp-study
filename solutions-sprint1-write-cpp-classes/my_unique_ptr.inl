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
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr&& src) noexcept : ptr{src.get()}
{
    src.ptr = nullptr;
}

template <typename T>
my_unique_ptr<T>& my_unique_ptr<T>::operator=(my_unique_ptr&& src) noexcept
{
    if (this != &src) swap(src);
    
    return *this;
}

template <typename T>
my_unique_ptr<T>::~my_unique_ptr()
{
    delete release();
}

template <typename T>
T* const my_unique_ptr<T>::operator->() const noexcept
{
    return ptr;
}

template <typename T>
T& my_unique_ptr<T>::operator*() const noexcept(noexcept(*std::declval<T>()))
{
    return *ptr;
}

template <typename T>
T* const my_unique_ptr<T>::get() const noexcept
{
    return operator->();
}

template <typename T>
void my_unique_ptr<T>::reset(T* const ptr) noexcept
{
    ~my_unique_ptr();
    this->ptr = ptr;
}

template <typename T>
void my_unique_ptr<T>::reset(std::nullptr_t) noexcept
{
    ~my_unique_ptr();
}

template <typename T>
T* my_unique_ptr<T>::release() noexcept
{
    T* ret = get();
    ptr = nullptr;
    return ret;
}

template <typename T>
void my_unique_ptr<T>::swap(my_unique_ptr& rhs) noexcept
{
    std::swap(ptr, rhs.ptr);
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

template <class T>
std::ostream& operator<<(std::ostream& os, const my_unique_ptr<T>& rhs)
{
    os << rhs.get();
    return os;
}