// if this header is included by a source,
// undef_macros.inl also should be included in the end of the source.

/**
 * @brief   checks if a value is in a specific range when _DEBUG macro is defined
 * @param   val     the value which will be checked
 * @param   lo      lower limit of the range
 * @param   hi      higher limit of the range
 * @param   expr    expression which will be forwarded to std::out_of_range
 * 
 * if val is not in [lo, hi] then throws std::out_of_range with expr
*/
#ifdef _DEBUG
#define debug_check_out_of_range(val, lo, hi, expr) _check_out_of_range((val), (lo), (hi), (expr), __FILE__, __LINE__, __FUNCTION_NAME__)
#else
#define debug_check_out_of_range(val, ...) (val)
#endif

#ifndef _my_exception
#define _my_exception

#include "my_format.h"
#include <algorithm>

namespace
{
    [[noreturn]] inline void _throw_out_of_range(const char* expr, const char* file, int line, const char* func)
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