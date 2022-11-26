#ifndef _timefunc
#define _timefunc

#include <chrono>
#include <utility>
#include <iostream>

#if __cplusplus >= 201103L

// returns std::pair
// first: return value of function
// second: elapsed time
template<class Time_t = std::chrono::milliseconds,
         class FPTime_t = std::chrono::duration<
            float, typename Time_t::period>,
         class Func, class ... Args>
auto
timefunc(Func func, Args&& ... args)
    -> std::pair<decltype(func(std::forward<Args>(args)...)),
                 FPTime_t>
{
    using std::chrono::system_clock;

    auto tp = system_clock::now();
    decltype(auto) ret = func(std::forward<Args>(args)...);

    return { std::forward<decltype(ret)>(ret),
             system_clock::now() - tp };
}

#else
template <class ... _>
void
timefunc(_&& ...)
{
    static_assert(false,
        "timefunc is a C++11 extension");
}

#endif // timefunc according to __cplusplus

#if __cplusplus >= 202002L

template <class Time_t = std::chrono::milliseconds,
          class CharT, class Traits, class Func, class ... Args>
decltype(auto)
run_and_print_elapsed_time(std::basic_ostream<CharT, Traits>& os,
                           Func func, Args&& ... args)
{
    auto&& [ret, elapsed] =
        timefunc<Time_t>(func, std::forward<Args>(args)...);
        
    os << elapsed << " elapsed\n";
    
    return std::forward<decltype(ret)>(ret);
}

#elif __cplusplus >= 201103L

template <class _>
constexpr const char* __time_suffix();

template <>
constexpr const char* __time_suffix<std::chrono::nanoseconds>()
{
    return "ns";
}

template <>
constexpr const char* __time_suffix<std::chrono::microseconds>()
{
    return "us";
}

template <>
constexpr const char* __time_suffix<std::chrono::milliseconds>()
{
    return "ms";
}

template <>
constexpr const char* __time_suffix<std::chrono::seconds>()
{
    return "s";
}

template <>
constexpr const char* __time_suffix<std::chrono::minutes>()
{
    return "m";
}

template <>
constexpr const char* __time_suffix<std::chrono::hours>()
{
    return "h";
}

template <class Time_t = std::chrono::milliseconds,
          class CharT, class Traits, class Func, class ... Args>
auto
run_and_print_elapsed_time(std::basic_ostream<CharT, Traits>& os,
                           Func func, Args&& ... args)
    -> decltype(func(std::forward<Args>(args)...))
{
    auto ret_and_time = timefunc<Time_t>(
        func, std::forward<Args>(args)...);
    
    os << ret_and_time.second.count() << __time_suffix<Time_t>()
        << " elapsed\n";
        
    return std::forward<decltype(ret_and_time.first)>(
            ret_and_time.first);
}

#else
template <class ... _>
void
run_and_print_elapsed_time(_&& ...)
{
    static_assert(false,
        "run_and_print_elapsed_time is a C++11 extension");
}

#endif  // run_and_print_elapsed_time according to __cplusplus

#endif // _timefunc