#include "my_shared_ptr.h"

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr() noexcept : ptr{nullptr}, refs{nullptr}
{
    
}

template <class T>
constexpr my_shared_ptr<T>::my_shared_ptr(std::nullptr_t) noexcept : ptr{nullptr}, refs{nullptr}
{
    
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(Y* ptr) : ptr{ptr}, refs{make_refs()}
{
    
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr& src) noexcept : ptr{src.get()}, refs{src.refs}
{
    inc_if_refs_valid();
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr<Y>& src) noexcept : ptr{static_cast<T*>(src.get())}, refs{src.refs}
{
    inc_if_refs_valid();
}

template <class T>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr&& src) noexcept : ptr{src.get()}, refs{src.refs}
{
    src.invalidate();
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_shared_ptr<Y>&& src) noexcept : ptr{static_cast<T*>(src.get())}, refs{src.refs}
{
    src.invalidate();
}

template <class T> template <class Y>
my_shared_ptr<T>::my_shared_ptr(my_unique_ptr<Y>&& src) : ptr{static_cast<T*>(src.get())}, refs{make_refs()}
{
    src.invalidate();
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr& src) noexcept
{
    if (this != &src)
    {
        dec_or_free_refs_if_refs_valid();
        copy_ptr_and_refs(src);
        inc_if_refs_valid();
    }
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(const my_shared_ptr<Y>& src) noexcept
{
    if (this != &src)
    {
        dec_or_free_refs_if_refs_valid();
        copy_ptr_and_refs(src);
        inc_if_refs_valid();
    }
    
    return *this;
}

template <class T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr&& src) noexcept
{
    if (this != &src)
    {
        dec_or_free_refs_if_refs_valid();
        copy_ptr_and_refs(src);
        src.invalidate();
    }
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr<Y>&& src) noexcept
{
    if (this != &src)
    {
        dec_or_free_refs_if_refs_valid();
        copy_ptr_and_refs(src);
        src.invalidate();
    }
    
    return *this;
}

template <class T> template <class Y>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_unique_ptr<Y>&& src)
{
    if (this != &src)
    {
        dec_or_free_refs_if_refs_valid();
        ptr = static_cast<T*>(src.get());
        make_refs();
        src.invalidate();
    }
    
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

template <typename T>
T* const my_shared_ptr<T>::operator->() const noexcept
{
    return ptr;
}

template <typename T>
T& my_shared_ptr<T>::operator*() const noexcept(noexcept(*std::declval<T>()))
{
    return *ptr;
}

template <typename T>
T* const my_shared_ptr<T>::get() const noexcept
{
    return operator->();
}

template <class T>
my_shared_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(ptr);
}

template <class T>
std::size_t* my_shared_ptr<T>::make_refs()
{
    return new std::size_t{1};
}

template <class T>
void my_shared_ptr<T>::invalidate() noexcept
{
    ptr = nullptr;
    refs = nullptr;
}

template <class T>
void my_shared_ptr<T>::copy_ptr_and_refs(const my_shared_ptr& src) noexcept
{
    ptr = src.get();
    refs = src.refs;
}

template <class T>
void my_shared_ptr<T>::copy_ptr_and_refs(my_shared_ptr&& src) noexcept
{
    ptr = src.get();
    refs = src.refs;
}

template <class T> template <class Y>
void my_shared_ptr<T>::copy_ptr_and_refs(const my_shared_ptr<Y>& src) noexcept
{
    ptr = static_cast<T*>(src.get());
    refs = src.refs;
}

template <class T> template <class Y>
void my_shared_ptr<T>::copy_ptr_and_refs(my_shared_ptr<Y>&& src) noexcept
{
    ptr = static_cast<T*>(src.get());
    refs = src.refs;
}

template <class T>
void my_shared_ptr<T>::inc_if_refs_valid() noexcept
{
    if (refs) ++*refs;
}

template <class T>
void my_shared_ptr<T>::dec_or_free_refs_if_refs_valid() noexcept
{
    if (refs)
        if (!--*refs)
        {
            delete ptr;
            delete refs;
            invalidate();
        }
}