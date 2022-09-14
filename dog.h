#ifndef _dog
#define _dog

#include <iostream>

class Dog
{
public:
    Dog() { std::cout << "Dog 생성\n"; }
    ~Dog() { std::cout << "Dog 소멸\n"; }
    Dog(const Dog&) { std::cout << "Dog 복사 생성\n"; }
    Dog(Dog&&) noexcept { std::cout << "Dog 이동 생성\n"; }
    Dog& operator=(const Dog&) { std::cout << "Dog 복사 할당\n"; return *this; }
    Dog& operator=(Dog&&) noexcept { std::cout << "Dog 이동 할당\n"; return *this; }
    void growl() const noexcept { std::cout << "으르렁\n"; }
    void bark() const noexcept { std::cout << "왈왈\n"; }
private:

};

#endif