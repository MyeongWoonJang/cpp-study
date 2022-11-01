#ifndef _vec
#define _vec
#include <cstddef>
#include <limits>

class vec
{
public:
	float length();
	float length2();
	void normalize();

private:
	float vec3[3];
};
#endif