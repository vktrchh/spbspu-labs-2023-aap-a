#ifndef INPUTSHAPESRC_HPP
#define INPUTSHAPESRC_HPP

#include <cstddef>
#include <istream>

#include "shape.hpp"

namespace zhalilov
{
  void inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input);
}

#endif
