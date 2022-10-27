#ifndef mat
#define mat

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

};
#endif