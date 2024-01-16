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
  void printCoords(Shape * shape);
  void scaleShapes(Shape ** list, size_t current_index, const double arguments[3], const size_t maxshapes);
  void printErrors(const char ** errors, size_t maxshapes);
}
#endif
