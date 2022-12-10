#include <iostream>

int subfunc1( int );
char subfunc2( float, char );

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
	std::cout << __FUNCTION__ << " entry\n";

	int var1{ };
	char var2{ };

	printmem( var1 );
	printmem( var2 );

	var1 = subfunc1( 1 );
	var2 = subfunc2( 1.1f, 'n' );

	std::cout << __FUNCTION__ << " exit\n";
}

int subfunc1( int a )
{
	std::cout << __FUNCTION__ << " entry\n";

	short b{ 12 };
	float c{ 3.14f };

	printmem( a );
	printmem( b );
	printmem( c );

	std::cout << __FUNCTION__ << " exit\n";

	return 0;
}

char subfunc2( float d, char e )
{
	std::cout << __FUNCTION__ << " entry\n";

	char f{ 'u' };
	double g{ 2.145134 };

	printmem( d );
	printmem( e );
	printmem( f );
	printmem( g );

	std::cout << __FUNCTION__ << " exit\n";

	return 'q';
}