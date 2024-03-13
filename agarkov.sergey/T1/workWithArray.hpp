#ifndef WORKWITHARRAY
#define WORKWITHARRAY

#include <cstddef>

namespace agarkov
{
  void expandArray(Shape** shapes, size_t capacity);
  void deleteArray(Shape** shapes, size_t size);
}

#endif
