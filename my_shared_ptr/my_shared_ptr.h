#ifndef _my_shared_ptr
#define _my_shared_ptr

#include "../my_unique_ptr/my_unique_ptr.h"
#include <type_traits>

template <class T>
class my_shared_ptr
{
public:
    constexpr my_shared_ptr(std::nullptr_t) noexcept;
    template <class Y>
    explicit my_shared_ptr(Y*);
    my_shared_ptr(const my_shared_ptr&) noexcept;
    template <class Y>
    my_shared_ptr(const my_shared_ptr<Y>&) noexcept;
    my_shared_ptr(my_shared_ptr&&) noexcept;
    template <class Y>
    my_shared_ptr(my_shared_ptr<Y>&&) noexcept;
    template <class Y>
    my_shared_ptr(my_unique_ptr<Y>&&);
    template <class Y>
    my_shared_ptr(const my_shared_ptr<Y>&, T*) noexcept;
    template <class Y>
    my_shared_ptr(my_shared_ptr<Y>&&, T*) noexcept;
    

private:
    T* ptr;
};

#endif