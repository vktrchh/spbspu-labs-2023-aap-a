#include "readArray.hpp"

template <typename T>
void marishin::readArray(std::istream& in, T* option, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    in >> option[i];
  }
}
