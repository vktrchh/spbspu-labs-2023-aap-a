#ifndef OUTPUTSHAPES_HPP
#define OUTPUTSHAPES_HPP

#include <iostream>
#include "shape.hpp"

namespace rebdev
{
  void printSum(Shape ** const shapes, size_t numOfShapes, std::ostream & out);
  void printShapes(Shape ** const shapes, size_t numOfShapes, std::ostream & out);
}

#endif
