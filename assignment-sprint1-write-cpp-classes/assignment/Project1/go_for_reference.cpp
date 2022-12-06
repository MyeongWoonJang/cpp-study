#include <iostream>

void swap(int* lhs, int* rhs)
{
    // lhs: left hand side, rhs: right hand side
    // lhs�� rhs�� ���� �����ϰ� ����,
    // lhs�� rhs�� ���� �������ϴ�.
    // ������ lhs ���� �������� ���� ������� ����.
    // �̿� ���� ������ lhs ���� ����� �ӽ� ���� tmp(temporary)�� �ʿ��մϴ�.

    // 1. tmp�� lhs�� ���� �����մϴ�.
    int* tmp = lhs;
    // 2. lhs�� rhs�� ���� �����մϴ�.
    lhs = rhs;
    // 3. rhs�� tmp�� ���� �����մϴ�.
    rhs = tmp;
}

int main()
{
    int a = 3;
    int b = 5;

    swap(&a, &b);

    std::cout << "a = " << a << ", b = " << b << '\n'; // output: a = 5, b = 3
}