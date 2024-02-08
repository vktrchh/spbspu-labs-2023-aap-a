#ifndef OUTPUT_OPERATIONS_HPP
#define OUTPUT_OPERATIONS_HPP
#include "shape.hpp"
#include <iostream>

namespace zakozhurnikova
{
  void printShapes(std::ostream& output, const Shape* const* shapes, size_t size);
}
#endif
