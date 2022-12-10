#include <iostream>

int subfunc1( int );
char subfunc2( float, char );
void subfunc3(char j, int k, double l); // function declaration
void subfunc4( );

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
	subfunc3( 'j', 3, 12.3 );
	subfunc4( );

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

void subfunc3( char j, int k, double l ) // function definition
{
	std::cout << __FUNCTION__ << " entry\n";

	char* pj = &j;
	int* pk = &k;
	double* pl = &l;

	std::cout << "pj: [" << static_cast<void*>( pj ) << "] + 1 = " << static_cast<void*>( pj + 1 ) << std::endl;
	std::cout << "pk: [" << pk << "] + 1 = " << pk + 1 << std::endl;
	std::cout << "pl: [" << pl << "] + 1 = " << pl + 1 << std::endl;

	std::cout << __FUNCTION__ << " exit\n";
}

void subfunc4( )
{
	std::cout << __FUNCTION__ << " entry\n";

	int arr[ 4 ]{ 1, 2, 3, 4 };

	for ( int i = 0; i < 4; ++i )
	{
		std::cout << *( arr + i ) << ' ';
	}
	
	std::cout << std::endl;

	std::cout << __FUNCTION__ << " exit\n";
}