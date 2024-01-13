#ifndef SHAPE_CREATION_HPP
#define SHAPE_CREATION_HPP
#include "shape.hpp"
namespace arakelyan
{
  arakelyan::Shape * defineShape(const char * sting);
  arakelyan::Shape * createPar(const char * string);
  arakelyan::Shape * createRect(const char * string);
  arakelyan::Shape * createDiam(const char * string);
}
#endif
