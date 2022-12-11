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

void memory_leak( );
void dangling_pointer( );
void* operator new( std::size_t sz );
void operator delete( void* ptr ) noexcept;

int main( )
{
    int* heap_int = new int{ 123 };

    printmem( heap_int );
    printmem( *heap_int );

    delete heap_int;

    int* heap_arr = new int[5] { 1, 2, 3, 4, 5 };

    printmem( heap_arr );
    printmem( *heap_arr );

    for ( int i = 0; i < 5; ++i )
        printmem( heap_arr[ i ] );

    delete[ ] heap_arr;
}

void memory_leak( )
{
    char* mem = new char[1'000'000'000] { 0 };
}

void dangling_pointer( )
{
    char* mem = new char[1000] { 0 };

    delete[ ] mem;

    std::cout << mem[ 100 ];
}

void* operator new( std::size_t sz )
{
    std::cout << __FUNCTION__ << " entry\n";

    if ( sz == 0 )
        ++sz; // avoid std::malloc(0) which may return nullptr on success

    while ( true )
    {
        if ( void* ptr = std::malloc( sz ) )
        {
            std::cout << __FUNCTION__ << " exit\n";
            return ptr;
        }

        if ( std::new_handler nh = std::get_new_handler( ) ) nh( );
        else throw std::bad_alloc{}; // required by [new.delete.single]/3
    }
}

void operator delete( void* ptr ) noexcept
{
    std::cout << __FUNCTION__ << " entry\n";

    std::free( ptr );

    std::cout << __FUNCTION__ << " exit\n";
}