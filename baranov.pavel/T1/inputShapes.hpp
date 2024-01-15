#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <iostream>

namespace baranov
{
  baranov::Shape * parseRectangle(const char * string);
  baranov::Shape * parseRing(const char * string);
  baranov::Shape * parseEllipse(const char * string);
  void parseScale(const char * string, point_t & scalePoint, size_t & scaleRatio);
  baranov::Shape * parseShape(char * string);
  void inputShapes(std::istream & input, Shape ** shapes, size_t & size, point_t & scalePoint, size_t & scaleRatio);
}

#endif

