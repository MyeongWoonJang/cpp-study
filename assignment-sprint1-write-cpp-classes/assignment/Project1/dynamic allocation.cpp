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

void memory_leak()
{
    char* mem = new char[1'000'000'000] {0};

    // delete[] mem이 없어 1GB의 메모리가 누수됩니다.
}

void dangling_pointer()
{
    char* mem = new char[1000] {0};  // 여기서 할당됩니다.

    delete[] mem;   // 여기서 반납됩니다.

    std::cout << mem[100];  // 반납된 메모리에 접근해 미정의 동작이 발생합니다.
}