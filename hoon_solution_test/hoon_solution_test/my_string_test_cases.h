#ifndef _mstest
#define _mstest

#define setup() std::cout << "\n\n" << __FUNCTION_NAME__ << "\n\n"

#include "my_string.h"

#include <iostream>
#include <string>

using namespace std;
using mstring = my_string<char>;

void TEST1()    // https://boycoding.tistory.com/178
{
    setup();
    mstring myName("Alex");
    std::cout << "My name is: " << myName;
}

void TEST2()    // https://boycoding.tistory.com/178
{
    setup();
    std::cout << "Enter your full name: ";
    mstring name;
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your age: ";
    mstring age;
    std::cin >> age;

    std::cout << "Your name is " << name << " and your age is " << age;
}

void TEST3()    // https://boycoding.tistory.com/178
{
    setup();
    
    mstring a("45");
    mstring b("11");

    std::cout << a + b << "\n"; // a and b will be appended, not added
    a += " volts";
    std::cout << a;
}

void TEST4()
{
    setup();
    
    mstring myName("Alex");
    std::cout << myName << " has " << myName.length() << " characters\n";
}

void TEST5()    // https://blockdmask.tistory.com/338
{
    setup();
    
    mstring str1 = "BlockDMask";
    mstring str2("BlogBlogBlogBlog");
    mstring str3(str1);
 
    //mstring을 생성하는 다양한 방법.
    std::cout << "==> onstructor" << std::endl;
    std::cout << "str1 = \"BlockDMask\" \n : " << str1 << std::endl << std::endl;
    std::cout << "str2(\"BlogBlogBlogBlog\") \n : " << str2 << std::endl << std::endl;
    std::cout << "str3(str1) \n : " << str3 << std::endl << std::endl;
 
    //push_back, pop_back
    std::cout << std::endl;
    std::cout << "==> mstring front, back example." << std::endl;
    str1.push_back('1');
    std::cout << "str1.push_back('1') : " << str1 << std::endl;
    str1.push_back('2');
    std::cout << "str1.push_back('2') : " << str1 << std::endl;
    str1.pop_back();
    std::cout << "str1.pop_back() :  " << str1 << std::endl;
    str1.pop_back();
    std::cout << "str1.pop_back() :  " << str1 << std::endl;
    str1.pop_back();
    std::cout << "str1.pop_back() :  " << str1 << std::endl;
 
    //operator+ stirng 덧셈.
    std::cout << std::endl;
    std::cout << "==> str1 += str2" << std::endl;
    str1 += str2;
    std::cout << str1 << std::endl;
           
    std::cout << std::endl;
}

void TEST6()    // https://blockdmask.tistory.com/338
{
    setup();
    
    mstring str2 = "BlogBlogBlogBlog";
 
    cout << "==> str2 original" << endl;
    cout << "str2 : " << str2 << endl;
    cout << "str2.size() : " << str2.size() << endl;
    cout << "str2.length() : " << str2.length() << endl;
    cout << "str2.capacity() : " << str2.capacity() << endl;
    
    cout << endl;
    str2.resize(4);
    cout << "==> str2.resize(4)" << endl;
    cout << "str2 : " << str2 << endl;
    cout << "str2.size() : " << str2.size() << endl;
    cout << "str2.length() : " << str2.length() << endl;
    cout << "str2.capacity() : " << str2.capacity() << endl;
 
    cout << endl;
    str2.shrink_to_fit();
    cout << "==> str2.shrink_to_fit()" << endl;
    cout << "str2 : " << str2 << endl;
    cout << "str2.size() : " << str2.size() << endl;
    cout << "str2.length() : " << str2.length() << endl;
    cout << "str2.capacity() : " << str2.capacity() << endl;
 
    cout << endl;
    str2.clear();
    cout << "==> str2.clear()" << endl;
    cout << "str2 : " << str2 << endl;
    cout << "str2.size() : " << str2.size() << endl;
    cout << "str2.length() : " << str2.length() << endl;
    cout << "str2.capacity() : " << str2.capacity() << endl;
 
    cout << endl;
}

void TEST7()    // https://blockdmask.tistory.com/338
{
    mstring str1 = "BlockDMask";
    mstring str2 = "BlogBlogBlogBlog";
 
    cout << "str1 : " << str1 << endl;
    cout << "str2 : " << str2 << endl;
    cout << endl;
    
    //string substr example.
    cout << "str1.substr(5) : " << str1.substr(5) << endl;
    cout << "str1.substr(5,1) : " << str1.substr(5,1) << endl;
    
    //string replace example.
    cout << "str1.replace(5, 2, str2) : " << str1.replace(5, 2, str2) << endl;
 
    //string swap example.
    cout << endl;
    mstring str3 = "C++ example";
    cout << "str2 : " << str2 << endl;
    cout << "str3 : " << str3 << endl;
 
    cout << endl;
    cout << "swap(str2, str3)" << endl;
    cout << "str2 : " << str2 << endl;
    cout << "str3 : " << str3 << endl;
 
    cout << endl;
}

void TEST8()    // https://blockdmask.tistory.com/338
{
    string str1 = "BlockDMask";
    string str2 = "BlogBlogBlogBlog";
 
    cout << "str1 : " << str1 << endl;
    cout << "str2 : " << str2 << endl;
    cout << endl;
 
    //find
    cout << "==> string find example." << endl;
    cout << "str1.find(\"DM\") : " << str1.find("DM") << endl;
    cout << "str2.find(\"Blog\") : " << str2.find("Blog") << endl;
    cout << "str2.find(\"Blog\", 5) : " << str2.find("Blog", 5) << endl;
 
    //operator[], at
    cout << endl;
    cout << "==> string operator[], at() example." << endl;
    cout << "str1[0] : " << str1[0] << endl;
    cout << "str1[3] : " << str1[3] << endl;
    cout << "str1[str1.size()-1] : " << str1[str1.size() - 1] << endl;
    cout << endl;
    cout << "str1.at(0) : " << str1.at(0) << endl;
    cout << "str1.at(3) : " << str1.at(3) << endl;
    cout << "str1.at(str1.size()-1) : " << str1.at(str1.size() - 1) << endl;
 
    //front, back
    cout << endl;
    cout << "==> string front, back example." << endl;
    cout << "str1[0] : " << str1[0] << endl;
    cout << "str1.at(0) : " << str1.at(0) << endl;
    cout << "str1.front() : " << str1.front() << endl;
    cout << endl;
    cout << "str1[str1.size()-1] : " << str1[str1.size() - 1] << endl;
    cout << "str1.at(str1.size()-1) : " << str1.at(str1.size() - 1) << endl;
    cout << "str1.back() : " << str1.back() << endl;
 
    cout << endl;
}

#endif