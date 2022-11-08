#ifndef _my_utils
#define _my_utils

#include <cstdint>
#include <cstddef>

namespace
{
    using word = std::uint_fast32_t;
    
    void _copy(void* src_begin, void* src_end, void* dest)
    {
        auto bsrc_begin = static_cast<byte*>(src_begin);
        auto bsrc_end = static_cast<byte*>(src_end);
        auto bdest = static_cast<byte*>(dest);
        
        auto wsrc_begin = static_cast<word*>(src_begin);
        auto wsrc_end = static_cast<word*>(src_end);
        auto wdest = static_cast<word*>(dest);
        
        auto rest = (bsrc_end - bsrc_begin) % sizeof(word);
        
        _word_copy(wsrc_begin, wsrc_end, wdest);
        _byte_copy(bsrc_end - rest, bsrc_end, bdest);
    }
    
    inline void _word_copy(word* src_begin, word* src_end, word* dest)
    {
        for(; src_begin < src_end; ++src_begin, ++dest)
            *dest = *src_begin
    }
    
    inline void _byte_copy(byte* src_begin, byte* src_end, byte* dest)
    {
        for(; src_begin < src_end; ++src_begin, ++dest)
            *dest = *src_begin;
    }
}

#endif