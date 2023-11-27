#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iostream>

namespace spiridonov
{
  size_t * extencionArray(const size_t * currentArray, const size_t strOld, size_t strNew);
  size_t * inputArray(std::istream& input, size_t & sizeOfStr);
}

#endif
