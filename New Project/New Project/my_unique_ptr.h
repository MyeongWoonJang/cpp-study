#ifndef my_unique_ptr
#define my_unique_ptr

#include <type_traits>

class my_unique_ptr
{
public:
	int* get( );
	int* release( );
	void reset( int* ptr );

private:
	int* ptr_obj;
};

#endif