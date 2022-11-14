#include "my_unique_ptr.h"

template <class T>
constexpr
my_unique_ptr<T>::
my_unique_ptr() noexcept
    : ptr{ nullptr }
{

}

template <class T>
constexpr
my_unique_ptr<T>::
my_unique_ptr(std::nullptr_t) noexcept
    : ptr{ nullptr }
{

}

template <class T>
my_unique_ptr<T>::
my_unique_ptr(T* const ptr) noexcept
    : ptr{ ptr }
{

}

template <class T>
my_unique_ptr<T>::
my_unique_ptr(my_unique_ptr&& other) noexcept
    : ptr{ other.get() }
{
    other.ptr = nullptr;
}

template <class T>
my_unique_ptr<T>&
my_unique_ptr<T>::
operator=(my_unique_ptr&& other) noexcept
{
    other.swap(*this);
    return *this;
}

template <class T>
my_unique_ptr<T>::
~my_unique_ptr()
{
    delete this->release();
}

template <class T>
T* const
my_unique_ptr<T>::
operator->() const noexcept
{
    return this->ptr;
}

template <class T>
T&
my_unique_ptr<T>::
operator*() const noexcept(noexcept(*std::declval<T>()))
{
    return *this->ptr;
}

template <class T>
T* const
my_unique_ptr<T>::
get() const noexcept
{
    return this->operator->();
}

template <class T>
T&
my_unique_ptr<T>::
operator[](std::size_t idx) const
{
    return this->get()[idx];
}

template <class T>
void
my_unique_ptr<T>::
reset(T* const ptr) noexcept
{
    my_unique_ptr{ ptr }.swap(*this);
}

template <class T>
void
my_unique_ptr<T>::
reset(std::nullptr_t) noexcept
{
    my_unique_ptr{}.swap(*this);
}

template <class T>
T*
my_unique_ptr<T>::
release() noexcept
{
    T* ret = this->get();
    this->ptr = nullptr;
    return ret;
}

template <class T>
void
my_unique_ptr<T>::
swap(my_unique_ptr& rhs) noexcept
{
    std::swap(this->ptr, rhs.ptr);
}

template <class T>
my_unique_ptr<T>::
operator bool() const noexcept
{
    return static_cast<bool>(this->ptr);
}

template <class T1, class T2>
bool
operator==(const my_unique_ptr<T1>& lhs,
           const my_unique_ptr<T2>& rhs) noexcept
{
    return lhs.get() == rhs.get();
}

template <class T1, class T2>
bool
operator!=(const my_unique_ptr<T1>& lhs,
           const my_unique_ptr<T2>& rhs) noexcept
{
    return lhs.get() != rhs.get();
}

template <class T1, class T2>
bool
operator<(const my_unique_ptr<T1>& lhs,
          const my_unique_ptr<T2>& rhs) noexcept
{
    return std::less<std::common_type_t<T1*, T2*>>{}(lhs.get(), rhs.get());
}

template <class T1, class T2>
bool
operator>(const my_unique_ptr<T1>& lhs,
          const my_unique_ptr<T2>& rhs) noexcept
{
    return rhs < lhs;
}

template <class T1, class T2>
bool
operator<=(const my_unique_ptr<T1>& lhs,
           const my_unique_ptr<T2>& rhs) noexcept
{
    return !(rhs < lhs);
}

template <class T1, class T2>
bool
operator>=(const my_unique_ptr<T1>& lhs,
           const my_unique_ptr<T2>& rhs) noexcept
{
    return !(lhs < rhs);
}

template <class T>
bool
operator==(const my_unique_ptr<T>& lhs,
           std::nullptr_t rhs) noexcept
{
    return !lhs;
}

template <class T>
bool
operator==(std::nullptr_t lhs,
           const my_unique_ptr<T>& rhs) noexcept
{
    return !rhs;
}

template <class T>
bool
operator!=(const my_unique_ptr<T>& lhs,
           std::nullptr_t rhs) noexcept
{
    return (bool)lhs;
}

template <class T>
bool
operator!=(std::nullptr_t lhs,
           const my_unique_ptr<T>& rhs) noexcept
{
    return (bool)rhs;
}

template <class T>
bool
operator<(const my_unique_ptr<T>& lhs,
          std::nullptr_t rhs) noexcept
{
    return std::less<T*>{}(lhs.get(), nullptr);
}

template <class T>
bool
operator<(std::nullptr_t lhs,
          const my_unique_ptr<T>& rhs) noexcept
{
    return std::less<T*>{}(nullptr, rhs.get());
}

template <class T>
bool
operator>(const my_unique_ptr<T>& lhs,
          std::nullptr_t rhs) noexcept
{
    return nullptr < lhs;
}

template <class T>
bool
operator>(std::nullptr_t lhs,
          const my_unique_ptr<T>& rhs) noexcept
{
    return rhs < nullptr;
}

template <class T>
bool
operator<=(const my_unique_ptr<T>& lhs,
           std::nullptr_t rhs) noexcept
{
    return !(nullptr < lhs);
}

template <class T>
bool
operator<=(std::nullptr_t lhs,
           const my_unique_ptr<T>& rhs) noexcept
{
    return !(rhs < nullptr);
}

template <class T>
bool
operator>=(const my_unique_ptr<T>& lhs,
           std::nullptr_t rhs) noexcept
{
    return !(lhs < nullptr);
}

template <class T>
bool
operator>=(std::nullptr_t lhs,
           const my_unique_ptr<T>& rhs) noexcept
{
    return !(nullptr < rhs);
}

template <class T>
std::ostream&
operator<<(std::ostream& os, const my_unique_ptr<T>& rhs)
{
    os << rhs.get();
    return os;
}