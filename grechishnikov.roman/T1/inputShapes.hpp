#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP

#include <istream>
#include "triangle.hpp"

namespace grechishnikov
{
  void inputShapes(std::istream &in);
  Shape* inputRectangle(const double* values, size_t size);
  Shape* inputTriangle(const double* values, size_t size);
  Shape* inputPolygon(const double* values, size_t size);
}

#endif
