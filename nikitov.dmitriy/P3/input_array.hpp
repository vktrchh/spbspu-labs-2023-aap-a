#ifndef INPUT_ARRAY_HPP
#define INPUT_ARRAY_HPP

#include <cstddef>
#include <utility>
#include <iostream>

namespace nikitov
{
  std::pair< char*, size_t > inputArray(std::istream &input, char* actualArray);
}
#endif
