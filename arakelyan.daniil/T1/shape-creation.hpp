#ifndef SHAPE_CREATION_HPP
#define SHAPE_CREATION_HPP
#include <cstddef>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void defineAndCreateShape(Shape **myShapes, size_t shapesCount, const char * sting);
  Shape * createPar(const char * string);
  Shape * createRect(const char * string);
  Shape * createDiam(const char * string);
  double * extractDataForShape(const char * string, double coordStorage[], size_t pointsCount, size_t wordLen);
  void freeMem(Shape **myShapes, size_t shapesCount);
}
#endif
