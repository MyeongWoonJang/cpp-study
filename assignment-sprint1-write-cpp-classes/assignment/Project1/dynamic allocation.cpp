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

// 변수를 전달하면 그 변수의 메모리 개요를 출력합니다.
template <typename Ty>
void printmem_stream(const Ty& var, std::ostream& os)    // function template definition
{
    // [메모리 시작 주소] ~ [메모리 끝 주소] - 타입 이름 : 타입의 크기 byte, value : 값
    // ex) [0x7ffc7d318a7c] ~ [0x7ffc7d318a7f] - int : 4 byte, value : 0
    // 형식으로 메모리를 출력됩니다.
    os << '[' << static_cast<const void*>(&var) << "] ~ [" << static_cast<const void*>(reinterpret_cast<const char*>(&var) + sizeof(var) - 1)
        << "] - " << typeid(var).name() << " : " << sizeof(var) << " byte, value : " << var << '\n';
}

template <typename Ty>
void printmem(const Ty& var)    // function template definition
{
    printmem_stream(var, std::cout);
}