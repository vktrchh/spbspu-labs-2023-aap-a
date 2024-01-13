#ifndef SHAPE_CREATION_HPP
#define SHAPE_CREATION_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace arakelyan
{
  arakelyan::Shape * defineAndCreateShape(const char * sting);
  arakelyan::Shape * createPar(const char * string);
  arakelyan::Shape * createRect(const char * string);
  arakelyan::Shape * createDiam(const char * string);
  void dataExtractionParAndDiam(const char * string, point_t & p1, point_t & p2, point_t &p3, const size_t wordLen);
  void dataExtractionRect(const char * string, point_t & p1, point_t & p2);
}
#endif
