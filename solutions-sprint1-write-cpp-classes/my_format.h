#ifndef _my_format
#define _my_format

#include <cstdio>

namespace
{
    #ifndef __FUNCTION_NAME__
    
    #ifdef __GNUC__     // if compiled by gcc/g++ use __PRETTY_FUNCTION__ for function name
    #define __FUNCTION_NAME__ __PRETTY_FUNCTION__
    #elif _MSC_VER      // elif compiled by msvc use __FUNCSIG__ for function name
    #define __FUNCTION_NAME__ __FUNCSIG__
    #else   // else use __FUNCTION__(standard) for function name
    #define __FUNCTION_NAME__ __FUNCTION__
    #endif
    
    #endif
    
    char* _get_fmtbuf(...)
    {
        static constexpr std::size_t FMTBUF_SIZE = 1 << 8;
        
        static char fmtbuf[FMTBUF_SIZE];
        return fmtbuf;
    }
    
    // _FMT changes a formatted expression into a string(char*)
    #define _FMT(...) _get_fmtbuf(sprintf(_get_fmtbuf(), ## __VA_ARGS__))
}

#endif