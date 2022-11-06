#ifndef _my_exception
#define _my_exception

#include <cstdio>

namespace
{
    #ifdef _ACTIVATE_EXCEPTION_MACRO
    
    char* _get_ebuf(...)
    {
        static constexpr std::size_t EBUF_SIZE = 1 << 8;
        
        static char a[EBUF_SIZE];
        return a;
    }
    
    #define _FMT(...) _get_ebuf(sprintf(_get_ebuf(), __VA_ARGS__))
    
    #endif
}

#endif