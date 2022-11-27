#include "constants.h"
#include "timefunc.h"
#include "track_allocator.h"

#include <vector>
#include <string>

#include <fstream>
#include <iostream>

using string = std::basic_string<char, std::char_traits<char>,
    TrackAllocator<char>>;
    
using vector = std::vector<char, TrackAllocator<char>>;

using CellType = string;           // 1. std::string
// using CellType = vector<char>;  // 2. std::vector<char>

using std::vector<std::array<CellType, ColCnt>> = CellDB;

CellDB loadDB(const std::string& file_path)
{
    CellDB ret(RowCnt);
    std::ifstream in(file_path);
    
    for (auto i = RowCnt & 0; i < RowCnt; ++i)
    {
        for (auto j = ColCnt & 0; j < ColCnt; ++j)
        {
            ret[i][j].reserve(MinLen);
            
            if (char ch = in.get(); ch == Delim) break;
            else ret[i][j].push_back(ch);
        }
    }
    
    return ret;     // NRVO
}

int main()
{
    std::ofstream ofs_memlog{ "memlog.txt" };
    TrackAllocator::set_ostream(ofs_memlog);
    
    run_and_print_elapsed_time(loadDB("DB.db"));
}