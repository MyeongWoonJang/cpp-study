#include <iostream>

template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os);  // function template declaration
template <typename Ty>
void printmem(const Ty& var);   // function template declaration

void memory_leak();
void dangling_pointer();

int main()
{
    dangling_pointer();
}

// ������ �����ϸ� �� ������ �޸� ���並 ����մϴ�.
template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os)    // function template definition
{
    // [�޸� ���� �ּ�] ~ [�޸� �� �ּ�] - Ÿ�� �̸� : Ÿ���� ũ�� byte, value : ��
    // ex) [0x7ffc7d318a7c] ~ [0x7ffc7d318a7f] - int : 4 byte, value : 0
    // �������� �޸𸮸� ��µ˴ϴ�.
    os << '[' << static_cast<const void*>(&var) << "] ~ [" << static_cast<const void*>(reinterpret_cast<const char*>(&var) + sizeof(var) - 1)
        << "] - " << typeid(var).name() << " : " << sizeof(var) << " byte, value : " << var << '\n';
}

template <typename Ty>
void printmem(const Ty& var)    // function template definition
{
    printmem_stream(var, std::cout);
}

void memory_leak()
{
    char* mem = new char[1'000'000'000] {0};

    // delete[] mem�� ���� 1GB�� �޸𸮰� �����˴ϴ�.
}

void dangling_pointer()
{
    char* mem = new char[1000] {0};  // ���⼭ �Ҵ�˴ϴ�.

    delete[] mem;   // ���⼭ �ݳ��˴ϴ�.

    std::cout << mem[100];  // �ݳ��� �޸𸮿� ������ ������ ������ �߻��մϴ�.
}