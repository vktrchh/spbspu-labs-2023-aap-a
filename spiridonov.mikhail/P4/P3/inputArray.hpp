#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iostream>

namespace spiridonov
{
  char* extencionArray(const char* currentArray, const size_t strOld, size_t strNew);
  char* inputArray(std::istream& input, size_t& sizeOfStr);
}

#endif
