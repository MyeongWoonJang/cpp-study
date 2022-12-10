#include <iostream>

int subfunc1( int );
char subfunc2( float, char );

int main( )
{
	std::cout << __FUNCTION__ << " entry\n";

	int val1{ subfunc1( 1 ) };
	char val2{ subfunc2( 1.1f, 'n' ) };

	std::cout << __FUNCTION__ << " exit\n";
}

int subfunc1( int a )
{
	std::cout << __FUNCTION__ << " entry\n";

	short b{ 12 };
	float c{ 3.14f };

	std::cout << __FUNCTION__ << " exit\n";

	return 0;
}

char subfunc2( float d, char e )
{
	std::cout << __FUNCTION__ << " entry\n";

	char f{ 'u' };
	double g{ 2.145134 };

	std::cout << __FUNCTION__ << " exit\n";

	return 'q';
}