#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include <iostream>
#include <cstddef>

#include "shape.h"

namespace skuratov
{
  void clearingShapes(Shape** shapes, size_t count);
  void inputRectangle(std::istream& input, Shape** shapes, size_t& count);
  void inputSquare();
  void inputDiamond();
  void inputParallelogram();
  Shape** inputShapes();
  void outputShapes();
}

#endif
