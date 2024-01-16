#ifndef STRING_PROCESSING_HPP
#define STRING_PROCESSING_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include <iostream>
namespace strelyaev
{
  char * inputString(std::istream & in);
  Shape * getShape(const char string[]);
  void isotrScale(Shape * shape, const point_t point, const double k);
}
#endif
