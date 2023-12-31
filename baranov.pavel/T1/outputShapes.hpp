#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include "shape.hpp"
#include <iostream>

namespace baranov
{
  double getSumArea(const Shape ** shapes, size_t count);
  void outputShapes(std::ostream & output, const Shape ** shapes, size_t count);
}

#endif

