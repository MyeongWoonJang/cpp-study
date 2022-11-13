#ifndef my_string
#define my_string

#include <cstring>

class my_string
{
public:
	char& at( size_t );
	char& front( );
	char& back( );
	const char* c_str( );
	const char* data( );
	bool empty( );
	size_t size( );
	size_t length( );
	void reserve( size_t );
	int capacity( );
	void shrink_to_fit( );
	void resize( size_t );
	void clear( );
	void insert( size_t, const char* );
	void erase( size_t, size_t );
	void push_back( char );
	void pop_back( );
	void append( char );
	int compare( const char* );
	void replace( const char*, const char* );
	const char* substr( size_t, size_t );
	int find( const char* );

private:

};

#endif