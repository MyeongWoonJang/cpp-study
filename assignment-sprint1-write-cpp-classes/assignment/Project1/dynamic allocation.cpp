#include <iostream>

template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os);  // function template declaration
template <typename Ty>
void printmem(const Ty& var);   // function template declaration

int main()
{
    // dynamic allocation
    // type* name = new type{initialization value};
    int* heap_int = new int{ 123 };

    printmem(heap_int);
    printmem(*heap_int);

    // dynamic deallocation
    // delete name;
    delete heap_int;

    // array dynamic allocation
    // type* name = new int[number of elements]{initialization values};
    int* heap_arr = new int[5] {1, 2, 3, 4, 5};

    printmem(heap_arr);
    printmem(*heap_arr);

    for (int i = 0; i < 5; ++i)
        printmem(heap_arr[i]);

    // array dynamic deallocation
    // delete[] name;
    delete[] heap_arr;
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