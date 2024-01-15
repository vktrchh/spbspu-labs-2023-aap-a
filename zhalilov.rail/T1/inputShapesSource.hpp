#ifndef INPUTSHAPESRC_HPP
#define INPUTSHAPESRC_HPP

#include <cstddef>
#include <istream>

#include "shape.hpp"

using shapeInputFunc = zhalilov::Shape *(*)(const char string[]);
namespace zhalilov
{
  Shape **inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input);
  void freeMemory(Shape **shapes, size_t size, const char string[]);
}

#endif
