#ifndef INPUTSHAPESRC_HPP
#define INPUTSHAPESRC_HPP

#include <cstddef>
#include <istream>

#include "Shape.hpp"

using shapeInputFunc = zhalilov::Shape *(*)(char string[]);
using shapeInputFuncArray = zhalilov::Shape *(*[])(char string[]);
namespace zhalilov
{
  Shape *inputShapesSource(size_t &inputedShapes, size_t &processedShapes, double &ratio, std::istream &input);
  shapeInputFunc identifyShape(char string[]);
  Shape *inputRectangle(char string[]);
}

#endif
