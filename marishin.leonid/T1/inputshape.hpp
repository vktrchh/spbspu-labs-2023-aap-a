#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP

#include "rectangle.hpp"
#include "triangle.hpp"
#include "ring.hpp"
#include <iostream>

namespace marishin
{
  Shape** inputShape(std::istream& in, size_t& shapeCount);
  void cleanupShapes(Shape** shapes, size_t count);
}

#endif
