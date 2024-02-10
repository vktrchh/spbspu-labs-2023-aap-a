#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP

#include <istream>
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace grechishnikov
{
  Shape* inputShape(const char* str);
  Shape* inputRectangle(const grechishnikov::point_t* points, size_t size);
  Shape* inputTriangle(const grechishnikov::point_t* points, size_t size);
  Shape* inputPolygon(const grechishnikov::point_t* points, size_t size);
  void freeShapes(Shape** shapes, size_t size);
  const char* parseName(const char* str);
  bool isEqualStr(const char* fStr, const char* sStr);
}

#endif
