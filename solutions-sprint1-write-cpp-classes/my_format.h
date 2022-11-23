#ifndef __FUNCTION_NAME__
    
    #ifdef __GNUC__     // if compiled by gcc/g++ use __PRETTY_FUNCTION__ for function name
        #define __FUNCTION_NAME__ __PRETTY_FUNCTION__
    #elif _MSC_VER      // elif compiled by msvc use __FUNCSIG__ for function name
        #define __FUNCTION_NAME__ __FUNCSIG__
    #else   // else use __FUNCTION__(standard) for function name
        #define __FUNCTION_NAME__ __FUNCTION__
    #endif
    
#endif

// _FMT changes a formatted expression into a string(char*)
#ifndef _FMT

    // reference source: https://stackoverflow.com/questions/40946062/c-format-string-macro
    #include <vector>
    
    #ifdef _MSC_VER
        #define MINIGINE_FORMAT_PRINTF _snprintf
    #else
        #define MINIGINE_FORMAT_PRINTF snprintf
    #endif
    
    #define _FMT(format, ...) \
    ([&]() \
    { \
        std::size_t size = MINIGINE_FORMAT_PRINTF(nullptr, 0, format, __VA_ARGS__) + 1; \
        std::vector<char> buf( size );\
        MINIGINE_FORMAT_PRINTF(buf.data(), size, format, __VA_ARGS__); \
        return buf; \
    }().data())

#endif