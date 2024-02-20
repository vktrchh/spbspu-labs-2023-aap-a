#ifndef OUTPUTSHAPES_HPP
#define OUTPUTSHAPES_HPP

#include <iostream>
#include "shape.hpp"
#include "base-types.hpp"

namespace rebdev
{
  void printSum(Shape ** const shapes, size_t numOfShapes, std::ostream & out);
  void printShapes(Shape ** const shapes, size_t numOfShapes, std::ostream & out);
  void printVertexes(const point_t & upRight, const point_t & lowLeft, std::ostream & out);
}

#endif
