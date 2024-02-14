#ifndef INPUT_OUTPUT_SHAPES_HPP
#define INPUT_OUTPUT_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace namestnikov
{
  void inputRectangle(std::istream & in, Shape ** shapes, size_t & count);
  void inputCircle(std::istream & in, Shape ** shapes, size_t & count);
  void inputComplexquad(std::istream & in, Shape ** shapes, size_t &  count);
  void fillShapesArray(Shape ** oldShapes, Shape ** currentShapes, size_t count);
  Shape ** inputShapes(std::istream & in, size_t & count);
  std::ostream & outputShapes(std::ostream & out, const Shape * const * shapes, size_t count);
}

#endif
