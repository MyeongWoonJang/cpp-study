#include <iostream>

int main()
{
	int a = 0;
	int& b = a;

	std::cout << &a << '\n';
	std::cout << b << '\n';
	std::cout << &b << '\n';

}
