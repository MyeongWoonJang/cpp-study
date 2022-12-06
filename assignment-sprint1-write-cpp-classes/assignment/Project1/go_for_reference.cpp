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
    // lhs�� rhs�� ���� �����ϰ� ����,
    // lhs�� rhs�� ���� �������ϴ�.
    // ������ lhs ���� �������� ���� ������� ����.
    // �̿� ���� ������ lhs ���� ����� �ӽ� ���� tmp(temporary)�� �ʿ��մϴ�.

    // 1. tmp�� lhs�� ���� �����մϴ�.
    int tmp = lhs;
    // 2. lhs�� rhs�� ���� �����մϴ�.
    lhs = rhs;
    // 3. rhs�� tmp�� ���� �����մϴ�.
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
    else // one_sum < two_sum (���� ���� ���� �ؾߵ���..?)
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
        std::cout << "min�� ������ �߸��Ǿ����ϴ�.\n";
    }

    if (&b != &max(a, b) ||
        &b != &max(b, c) ||
        &c != &max(a, c))
    {
        std::cout << "max�� ������ �߸��Ǿ����ϴ�.\n";
    }

    if (&c != &median_of_three(a, b, c))
    {
        std::cout << "median_of_three�� ������ �߸��Ǿ����ϴ�.\n";
    }

    std::cout << "\"...�� ������ �߸��Ǿ����ϴ�.\" ����� �� ���Դٸ� ����!\n";
}