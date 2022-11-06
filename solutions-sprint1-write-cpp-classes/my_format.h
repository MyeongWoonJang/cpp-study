#ifndef _my_format
#define _my_format

#include <cstdio>

namespace
{
    char* _get_fmtbuf(...)
    {
        static constexpr std::size_t FMTBUF_SIZE = 1 << 8;
        
        static char a[FMTBUF_SIZE];
        return a;
    }
    
    #define _FMT(...) _get_fmtbuf(sprintf(_get_fmtbuf(), __VA_ARGS__))
}

#endif