#ifndef INPUTSHAPESRC_HPP
#define INPUTSHAPESRC_HPP

#include <cstddef>
#include <istream>

#include "Shape.hpp"

using shapeInputFunc = zhalilov::Shape *(*)(const char string[]);
namespace zhalilov
{
  Shape **inputShapesSource(size_t &inputedShapes, size_t &processedShapes, double &ratio, std::istream &input);
  shapeInputFunc identifyShape(const char string[]);
  Shape *inputRectangle(const char string[]);
  bool isScaleInputed(const char string[]);
}

#endif
