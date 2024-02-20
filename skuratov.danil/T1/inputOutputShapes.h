#ifndef INPUT_OUTPUT_HPP
#define INPUT_OUTPUT_HPP

#include "shape.h"

namespace skuratov
{
  void clearingShapes();
  void inputRectangle();
  void inputSquare();
  void inputDiamond();
  void inputParallelogram();
  Shape** inputShapes();
  void outputShapes();
}

#endif
