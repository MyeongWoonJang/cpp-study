#ifndef my_string
#define my_string

#include <cstring>

class my_string
{
public:
	char at( unsigned int );
	char front( );
	char back( );
	const char* c_str( );
	const char* data( );
	bool empty( );
	size_t size( );
	size_t length( );
	void reserve( unsigned int );
	int capacity( );

private:

};

#endif