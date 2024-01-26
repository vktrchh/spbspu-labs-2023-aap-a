#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <ostream>
#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace piyavkin
{
  void output(std::ostream& out, Shape** shapes, size_t shapeCount);
}
#endif
