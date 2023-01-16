#ifndef _my_string
#define _my_string

#include <cstring>

class my_string
{
public:
	const char& at(const size_t location) const;
	const char& front() const;
	const char* c_str() const;
	const char* data() const;
	bool empty() const;
	int size() const;
	int length() const;
	void reserve(const size_t size);
	size_t capacity();
	void shrink_to_fit();
	void resize(const size_t size);
	void clear();
	void insert(const size_t location, const char* insert_str);
	void erase(const size_t location, const size_t number_of_char);
	void push_back(const char inserted_char);
	void pop_back();
	void append(const char inserted_char);
	int compare(const char* other) const;
	void replace(size_t src_location, size_t number_of_src, const char* other_str, size_t other_location, size_t number_of_other);
	const my_string& substr(const size_t location, const size_t number_of_char);
	int find(const char* str) const;

private:
	size_t	byteObtained;
	char*	myString;
	int		m_length;
};
#endif
