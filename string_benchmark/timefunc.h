#ifndef _timefunc
#define _timefunc

#include <chrono>
#include <utility>
#include <iostream>

template<class Time_t = std::chrono::milliseconds,
         class FPTime_t = std::chrono::duration<
            float, typename Time_t::period>,
         class Func, class ... Args>
float
timefunc(Func func, Args&& ... args)
{
    using std::chrono::system_clock;

    auto tp = system_clock::now();
    func(std::forward<Args>(args)...);

    return FPTime_t(system_clock::now() - tp).count();
}

#if __cplusplus >= 202002L

template <class Time_t = std::chrono::milliseconds,
          class CharT, class Traits, class Func, class ... Args>
void
run_and_print_elapsed_time(std::basic_ostream<CharT, Traits>& os,
                           Func func, Args&& ... args)
{
    os << timefunc<Time_t>(func, std::forward<Args>(args)...)
        << " elapsed\n";
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
void
run_and_print_elapsed_time(std::basic_ostream<CharT, Traits>& os,
                           Func func, Args&& ... args)
{
    os << timefunc<Time_t>(func, std::forward<Args>(args)...)
        << __time_suffix<Time_t>() << " elapsed\n";
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