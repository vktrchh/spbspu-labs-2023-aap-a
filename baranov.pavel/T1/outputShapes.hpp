#ifndef OUTPUT_SHAPES_HPP
#define OUTPUT_SHAPES_HPP
#include "shape.hpp"
#include <iostream>

namespace baranov
{
  double getSumArea(Shape ** const shapes, size_t count);
  void outputShapes(std::ostream & output, Shape ** const shapes, size_t count);
}

#endif

