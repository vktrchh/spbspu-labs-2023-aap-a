#ifndef SHAPES_I_O_H
#define SHAPES_I_O_H
#include <ostream>
#include <cstddef>
#include "base-types.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Complexquad.h"

namespace zaitsev
{
  double readNextValue();
  Shape* readRectangle(char* param);
  Shape* readComplexquad(char* param);
  void readScale(char* param, point_t& center, double& factor);
  Shape* shapesInput(const std::string& input_str);
  std::ostream& shapesOutput(std::ostream& output, Shape** shapes, size_t size);
}
#endif
