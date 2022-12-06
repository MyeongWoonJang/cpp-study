#include <iostream>

void swap(int* lhs, int* rhs)
{
    // lhs: left hand side, rhs: right hand side
    // lhs에 rhs의 값을 대입하고 나면,
    // lhs와 rhs의 값이 같아집니다.
    // 기존의 lhs 값은 대입으로 인해 사라지고 말죠.
    // 이에 따라 기존의 lhs 값을 기억할 임시 변수 tmp(temporary)가 필요합니다.

    // 1. tmp에 lhs의 값을 대입합니다.
    int* tmp = lhs;
    // 2. lhs에 rhs의 값을 대입합니다.
    lhs = rhs;
    // 3. rhs에 tmp의 값을 대입합니다.
    rhs = tmp;
}

int main()
{
    int a = 3;
    int b = 5;

    swap(&a, &b);

    std::cout << "a = " << a << ", b = " << b << '\n'; // output: a = 5, b = 3
}