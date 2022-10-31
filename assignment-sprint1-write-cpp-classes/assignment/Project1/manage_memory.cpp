#include <iostream>

int main()
{
    std::cout << __FUNCTION__ << " entry\n";    

    int ret = 0;

    std::cout << __FUNCTION__ << " exit\n";

    return ret;        
}