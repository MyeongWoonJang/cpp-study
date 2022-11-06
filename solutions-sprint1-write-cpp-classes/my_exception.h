#ifndef _my_exception
#define _my_exception

#include "my_format.h"
#include <algorithm>

namespace
{
    
    #ifdef _DEBUG
    
    #ifdef __GNUC__
    #define debug_check_out_of_range(val, lo, hi, expr) _check_out_of_range((val), (lo), (hi), (expr), __FILE__, __LINE__, __PRETTY_FUNCTION__)
    #elif _MSC_VER
    #define debug_check_out_of_range(val, lo, hi, expr) _check_out_of_range((val), (lo), (hi), (expr), __FILE__, __LINE__, __FUNCSIG__)
    #else
    #define debug_check_out_of_range(val, lo, hi, expr) _check_out_of_range((val), (lo), (hi), (expr), __FILE__, __LINE__, __FUNCTION__)
    #endif
    
    #else
    #define debug_check_out_of_range(val, ...) (val)
    #endif
 
    inline void _throw_out_of_range(const char* expr, const char* file, int line, const char* func)
    {
        throw std::out_of_range{_FMT("in %s:%d:%s:\n%s\n", file, line, func, expr)};
    }
    
    template <class T>
    inline void _no_chain_check_out_of_range(const T& val, const T& lo, const T& hi, const char* expr, const char* file, int line, const char* func)
    {
        if (std::clamp(val, lo, hi) != val) _throw_out_of_range(expr, file, line, func);
    }
 
    template <class T>
    T& _check_out_of_range(T& val, const T& lo, const T& hi, const char* expr, const char* file, int line, const char* func)
    {
        _no_chain_check_out_of_range(val, lo, hi, expr, file, line, func);
        return val;
    }
 
    template <class T>
    const T& _check_out_of_range(const T& val, const T& lo, const T& hi, const char* expr, const char* file, int line, const char* func)
    {
        _no_chain_check_out_of_range(val, lo, hi, expr, file, line, func);
        return val;
    }
}

#endif