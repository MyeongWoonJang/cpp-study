#include <iostream>

void swap( int& lhs, int& rhs );

int main( )
{
	int a{ 3 };
	int b{ 5 };

	swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
}

void swap( int& lhs, int& rhs )
{
	int temp{ lhs };
	lhs = rhs;
	rhs = temp;
}