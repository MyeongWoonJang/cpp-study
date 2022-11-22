//#define _DEBUG

#include <iostream>
#include "my_string.h"

using string = my_string<char>;

#define setup() std::cout << "\n\n" << __FUNCTION_NAME__ << "\n\n"

void TEST1()    // https://boycoding.tistory.com/178
{
    setup();
    string myName("Alex");
    std::cout << "My name is: " << myName;
}

void TEST2()    // https://boycoding.tistory.com/178
{
    setup();
    std::cout << "Enter your full name: ";
    string name;
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    string age;
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age;
}

void TEST3()    // https://boycoding.tistory.com/178
{
    setup();
    
    std::string a("45");
    std::string b("11");

    std::cout << a + b << "\n"; // a and b will be appended, not added
    a += " volts";
    std::cout << a;
}

int main()
{
    //TEST1();
    //TEST2();
    TEST3();
}