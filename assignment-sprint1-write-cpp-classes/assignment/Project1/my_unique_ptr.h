#ifndef _my_unique_ptr
#define _my_unique_ptr

#include <type_traits>

class my_unique_ptr
{
public:
	int* get();
	int* release();
	void reset(int* other);

private:
	int* pObject;

};
#endif


