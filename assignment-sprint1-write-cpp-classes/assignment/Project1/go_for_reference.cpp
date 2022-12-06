#include <iostream>

struct TestScore
{
    int math;
    int english;
    int physics;
    int chemicals;
};

void swap(int& lhs, int& rhs)
{
    // lhs: left hand side, rhs: right hand side
    // lhs에 rhs의 값을 대입하고 나면,
    // lhs와 rhs의 값이 같아집니다.
    // 기존의 lhs 값은 대입으로 인해 사라지고 말죠.
    // 이에 따라 기존의 lhs 값을 기억할 임시 변수 tmp(temporary)가 필요합니다.

    // 1. tmp에 lhs의 값을 대입합니다.
    int tmp = lhs;
    // 2. lhs에 rhs의 값을 대입합니다.
    lhs = rhs;
    // 3. rhs에 tmp의 값을 대입합니다.
    rhs = tmp;
}

TestScore& min(TestScore& lhs, TestScore& rhs)
{
    int lhs_sum = lhs.math + lhs.english + lhs.physics + lhs.chemicals;
    int rhs_sum = rhs.math + rhs.english + rhs.physics + rhs.chemicals;

    if (lhs_sum < rhs_sum)
        return lhs;
    else
        return rhs;
}

TestScore& max(TestScore& lhs, TestScore& rhs)
{
    int lhs_sum = lhs.math + lhs.english + lhs.physics + lhs.chemicals;
    int rhs_sum = rhs.math + rhs.english + rhs.physics + rhs.chemicals;

    if (lhs_sum > rhs_sum)
        return lhs;
    else
        return rhs;
}

TestScore& median_of_three(TestScore& one, TestScore& two, TestScore& three)
{
    int one_sum = one.math + one.english + one.physics + one.chemicals;
    int two_sum = two.math + two.english + two.physics + two.chemicals;
    int three_sum = three.math + three.english + three.physics + three.chemicals;

    if (one_sum > two_sum)
    {
        if (one_sum > three_sum)
        {
            if (two_sum > three_sum)
                return two;
            else
                return three;
        }
        else
            return one;
    }
    else // one_sum < two_sum (같은 경우는 어찌 해야되지..?)
    {
        if (one_sum > three_sum)
        {
            return one;
        }
        else
        {
            if (two_sum > three_sum)
                return three;
            else
                return two;
        }
    }
}

int main()
{
    TestScore a{ 20, 50, 30, 40 };
    TestScore b{ 40, 60, 90, 70 };
    TestScore c{ 10, 30, 60, 60 };

    if (&a != &min(a, b) ||
        &c != &min(b, c) ||
        &a != &min(a, c))
    {
        std::cout << "min의 구현이 잘못되었습니다.\n";
    }

    if (&b != &max(a, b) ||
        &b != &max(b, c) ||
        &c != &max(a, c))
    {
        std::cout << "max의 구현이 잘못되었습니다.\n";
    }

    if (&c != &median_of_three(a, b, c))
    {
        std::cout << "median_of_three의 구현이 잘못되었습니다.\n";
    }

    std::cout << "\"...의 구현이 잘못되었습니다.\" 출력이 안 나왔다면 성공!\n";
}