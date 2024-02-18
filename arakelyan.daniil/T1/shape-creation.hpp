#ifndef SHAPE_CREATION_HPP
#define SHAPE_CREATION_HPP
#include <cstddef>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void defineAndCreateShape(Shape **myShapes, const size_t shapesCount, const char * sting);
  Shape * createPar(const char * string);
  Shape * createRect(const char * string);
  Shape * createDiam(const char * string);
  double * extractDataForShape(const char * string, double coordStorage[], const size_t pointsCount, const size_t wordLen);
}
#endif
