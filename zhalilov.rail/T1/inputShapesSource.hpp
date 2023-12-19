#ifndef INPUTSHAPESRC_HPP
#define INPUTSHAPESRC_HPP

#include <cstddef>
#include <istream>

#include "Shape.hpp"
#include "ShapeSource.hpp"

using shapeInputFunc = zhalilov::Shape *(*)(const char string[]);
namespace zhalilov
{
  ShapeSource *inputShapesSource(ShapeSource *shapeSource, std::istream &input);
  shapeInputFunc identifyShape(const char string[]);
  bool inputScale(ShapeSource *shapeSource, const char string[]);
  Shape *inputRectangle(const char string[]);
}

#endif
