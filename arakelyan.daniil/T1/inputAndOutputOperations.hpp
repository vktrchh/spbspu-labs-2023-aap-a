#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  void inputScaleParam(const char *string, point_t &point, double &k);
  void shapeOutput(std::ostream &output, Shape * const * shapes, const size_t shapesCount);
}
#endif
