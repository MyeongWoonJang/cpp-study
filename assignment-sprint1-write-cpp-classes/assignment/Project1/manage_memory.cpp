#include <iostream>

int subfunc1(short);    // function declaration
char subfunc2(int, char);   // function declaration

template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os);
template <typename Ty>
void printmem(const Ty& var);

int main()
{
    std::cout << __FUNCTION__ << " entry\n";    

    int a = 0;
    double b = 3.14;
    char c = 'c';

    printmem(a);
    printmem(b);
    printmem(c);

    int ret = 0;
    int func1{};
    char func2{};

    func1 = subfunc1(100);
    func2 = subfunc2(4, 'f');

    std::cout << __FUNCTION__ << " exit\n";

    return ret;        
}

int subfunc1(short d)   // function definition
{
    std::cout << __FUNCTION__ << " entry\n";    // output: func entry

    float e = 2.7f;
    bool f = true;

    printmem(d);
    printmem(e);
    printmem(f);

    std::cout << __FUNCTION__ << " exit\n";     // output: func exit

    return 0;
}

char subfunc2(int g, char h)    // function definition
{
    std::cout << __FUNCTION__ << " entry\n";    // output: func entry

    double i = 1.017;

    printmem(g);
    printmem(h);
    printmem(i);

    std::cout << __FUNCTION__ << " exit\n";     // output: func exit

    return 'f';
}

template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os)
{
    os << '[' << static_cast<const void*>(&var) << "] ~ [" << static_cast<const void*>(reinterpret_cast<const char*>(&var) + sizeof(var) - 1) << "] - " << typeid(var).name() << " : " << sizeof(var) << " byte, value : " << var << '\n';
}

template <typename Ty>
void printmem(const Ty& var)
{
    printmem_stream(var, std::cout);
}