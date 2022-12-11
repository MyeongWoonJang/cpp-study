#include <iostream>

template <typename Ty>
void printmem_stream( const Ty& var, std::ostream& os );  // function template declaration
template <typename Ty>
void printmem( const Ty& var );   // function template declaration

// ������ �����ϸ� �� ������ �޸� ���並 ����մϴ�.
template <typename Ty>
void printmem_stream( const Ty& var, std::ostream& os )    // function template definition
{
    // [�޸� ���� �ּ�] ~ [�޸� �� �ּ�] - Ÿ�� �̸� : Ÿ���� ũ�� byte, value : ��
    // ex) [0x7ffc7d318a7c] ~ [0x7ffc7d318a7f] - int : 4 byte, value : 0
    // �������� �޸𸮸� ����մϴ�.
    os << '[' << static_cast<const void*>( &var ) << "] ~ [" << static_cast<const void*>( reinterpret_cast<const char*>( &var ) + sizeof( var ) - 1 )
        << "] - " << typeid( var ).name( ) << " : " << sizeof( var ) << " byte, value : " << var << '\n';
}

template <typename Ty>
void printmem( const Ty& var )    // function template definition
{
    printmem_stream( var, std::cout );
}

int main( )
{
    int* heap_int = new int{ 123 };

    printmem( heap_int );
    printmem( *heap_int );

    delete heap_int;
}