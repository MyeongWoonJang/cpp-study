#ifndef my_string
#define my_string

#include <cstring>

class my_string
{
public:
	char& at( size_t location );
	char& front( );
	char& back( );
	const char* c_str( );
	const char* data( );
	bool empty( );
	size_t size( );
	size_t length( );
	void reserve( size_t num );
	int capacity( );
	void shrink_to_fit( );
	void resize( size_t num );
	void clear( );
	void insert( size_t location, const char* str );
	void erase( size_t location, size_t num );
	void push_back( char word );
	void pop_back( );
	void append( char word );
	int compare( const char* str );
	void replace( size_t location, size_t num, size_t str_location, size_t str_num, const char* str );
	const char* substr( size_t location, size_t num );
	int find( const char* str );

private:
	size_t num;
	char* str;
};

#endif