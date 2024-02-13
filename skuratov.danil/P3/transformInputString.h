#ifndef TRANSFORM_INPUT_STRING_H
#define TRANSFORM_INPUT_STRING_H

#include <cstddef>
#include <istream>

namespace skuratov
{
  char* transformInputString(std::istream& in, size_t& size);
}

#endif
