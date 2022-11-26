#include "constants.h"
#include "timefunc.h"

#include <vector>
#include <string>

#include <fstream>
#include <iostream>

using CellType = std::string;           // 1. std::string
// using CellType = std::vector<char>;  // 2. std::vector<char>

using std::vector<std::array<std::CellType, ColCnt>> = CellDB;

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
    
    [[maybe_unused]] run_and_print_elapsed_time(loadDB("DB.db"));
}