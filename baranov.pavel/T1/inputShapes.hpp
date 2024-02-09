#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include <istream>

namespace baranov
{
  Shape * parseRectangle(const char * string);
  Shape * parseRing(const char * string);
  Shape * parseEllipse(const char * string);
  void parseScale(const char * string, point_t & scalePoint, size_t & scaleRatio);
  Shape * parseShape(const char * string);
  void freeShapes(Shape ** shapes, size_t size);
  void inputShapes(std::istream & input, Shape ** shapes, size_t & size, point_t & scalePoint, size_t & scaleRatio);
}

#endif

