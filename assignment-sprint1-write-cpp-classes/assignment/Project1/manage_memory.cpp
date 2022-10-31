#include <iostream>

int subfunc1(short);    // function declaration
char subfunc2(int, char);   // function declaration

int main()
{
    std::cout << __FUNCTION__ << " entry\n";    

    int ret = 0;
    int func1{};
    char func2{};

    func1 = subfunc1(100);
    func2 = subfunc2(4, 'c');

    std::cout << __FUNCTION__ << " exit\n";

    return ret;        
}

int subfunc1(short d)   // function definition
{
    std::cout << __FUNCTION__ << " entry\n";    // output: func entry

    float e = 2.7f;
    bool f = true;

    std::cout << __FUNCTION__ << " exit\n";     // output: func exit

    return 0;
}

char subfunc2(int g, char h)    // function definition
{
    std::cout << __FUNCTION__ << " entry\n";    // output: func entry

    double i = 1.017;

    std::cout << __FUNCTION__ << " exit\n";     // output: func exit

    return 'f';
}