#ifndef _mat
#define _mat

#include <cstddef>
#include <limits>

class mat
{
public:
	float determinant() const;
	float* inverse() const;
	float* transpose() const;
	float* affineInverse() const;
	float* inverseTranspose() const;

private:
	float mat3[3][3];

};
#endif