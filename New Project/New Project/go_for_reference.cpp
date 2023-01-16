#include <iostream>

struct TestScore
{
	int math;
	int english;
	int physics;
	int chemicals;
};

int sum( TestScore& ts );
TestScore& min( TestScore& a, TestScore& b );
TestScore& max( TestScore& a, TestScore& b );
TestScore& median_of_three( TestScore& a, TestScore& b, TestScore& c );

int main( )
{
	TestScore a{ 20, 50, 30, 40 };
	TestScore b{ 40, 60, 90, 70 };
	TestScore c{ 10, 30, 60, 60 };

	if ( &a != &min( a, b ) ||
		 &c != &min( b, c ) ||
		 &a != &min( a, c ) )
	{
		std::cout << "min의 구현이 잘못되었습니다.\n";
	}

	if ( &b != &max( a, b ) ||
		 &b != &max( b, c ) ||
		 &c != &max( a, c ) )
	{
		std::cout << "max의 구현이 잘못되었습니다.\n";
	}

	if ( &c != &median_of_three( a, b, c ) )
	{
		std::cout << "median_of_three의 구현이 잘못되었습니다.\n";
	}
}

int sum( TestScore& ts )
{
	return ts.math + ts.english + ts.physics + ts.chemicals;
}

TestScore& min( TestScore& a, TestScore& b )
{
	int sum_a{ sum( a ) };
	int sum_b{ sum( b ) };

	return ( sum_a < sum_b ) ? a : b;
}

TestScore& max( TestScore& a, TestScore& b )
{
	int sum_a{ sum( a ) };
	int sum_b{ sum( b ) };
	
	return ( sum_a > sum_b ) ? a : b;
}

TestScore& median_of_three( TestScore& a, TestScore& b, TestScore& c )
{
	int sum_a{ sum( a ) };
	int sum_b{ sum( b ) };
	int sum_c{ sum( c ) };

	if ( sum_a > sum_b && sum_a < sum_c )
		return a;
	else if ( sum_b > sum_a && sum_b < sum_c )
		return b;
	else if ( sum_c > sum_a && sum_c < sum_b )
		return c;
}