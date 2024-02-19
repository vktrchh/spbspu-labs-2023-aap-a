#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace stepanov
{
  void intputRectangle(std::istream& input, Shape ** shapes, size_t& size_shapes);
  void intputCircle(std::istream& input, Shape ** shapes, size_t& size_shapes);
  void intputEllipse(std::istream& input, Shape ** shapes, size_t& size_shapes);
  void intputSquare(std::istream& input, Shape ** shapes, size_t& size_shapes);
}
#endif
