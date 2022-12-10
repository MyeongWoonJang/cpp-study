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

int sum(TestScore& ts)
{
    return ts.math + ts.english + ts.physics + ts.chemicals;
}

TestScore& min(TestScore& lhs, TestScore& rhs)
{
    if (sum(lhs) < sum(rhs))
        return lhs;
    else
        return rhs;
}

TestScore& max(TestScore& lhs, TestScore& rhs)
{
    if (sum(lhs) > sum(rhs))
        return lhs;
    else
        return rhs;
}

TestScore& median_of_three(TestScore& one, TestScore& two, TestScore& three)
{
    return min(max(one, two), max(two, three));
}

int main()
{
    TestScore a{ 20, 50, 30, 40 };  // 140
    TestScore b{ 40, 60, 90, 70 };  // 260
    TestScore c{ 10, 30, 60, 60 };  // 160

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