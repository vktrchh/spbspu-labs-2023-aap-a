#ifndef SHAPEINPUT_HPP
#define SHAPEINPUT_HPP

#include <istream>

#include "shape.hpp"
#include "base-types.hpp"

namespace gladyshev
{
  void shapeInput(std::istream& in, Shape ** shapes, point_t& pos, size_t& counter, double& factor);
}

#endif
