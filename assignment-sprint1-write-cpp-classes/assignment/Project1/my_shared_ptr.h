#ifndef _my_shared_ptr
#define _my_shared_ptr

#include <type_traits>

class my_shared_ptr
{
public:
	int* get();
	size_t use_count();
	void reset(int* other);

private:
	int count;
	int* pObject;
};
#endif