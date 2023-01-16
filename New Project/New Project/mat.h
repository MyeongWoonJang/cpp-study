#ifndef mat
#define mat

#include <cstddef>
#include <limits>

class mat
{
public:
	double determinant( );
	double** inverse( );
	double** transpose( );
	double** affineInverse( );
	double** inverseTranspose( );

private:
	double** m_mat;
};

#endif