#ifndef my_unique_ptr
#define my_unique_ptr

#include <type_traits>

class my_unique_ptr
{
public:
	int* get();
	void release();
	void reset(int* other);

private:
	int* pObject;

};
#endif


