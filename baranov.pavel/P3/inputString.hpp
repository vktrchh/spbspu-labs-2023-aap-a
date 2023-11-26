#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP
#include <iostream>

char * expandString(const char * string, const size_t size, const size_t newSize);
char * inputString(std::istream & input, size_t & stringSize);

#endif

