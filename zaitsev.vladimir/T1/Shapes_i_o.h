#ifndef SHAPES_I_O_H
#define SHAPES_I_O_H
#include <iostream>
#include <cstddef>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  double readNextValue(std::istream& input);
  Shape* readRectangle(std::istream& input);
  Shape* readComplexquad(std::istream& input);
  Shape* readParallelogram(std::istream& input);
  void readScale(std::istream& input, point_t& center, double& factor);
  std::ostream& shapesOutput(std::ostream& output, const Shape* const* shapes, size_t size);
  void freeMemory(Shape** shapes, size_t size);
  void processShapeInput(std::istream& input, Shape** shapes, size_t& size, Shape* (*handler)(std::istream&));
}
#endif
