#ifndef my_shared_ptr
#define my_shared_ptr

#include <type_traits>

class my_shared_ptr
{
public:
	int* get( );
	unsigned int use_count( );
	void reset( int* ptr );

private:
	int* objPtr;
	int* cntPtr;
};

#endif