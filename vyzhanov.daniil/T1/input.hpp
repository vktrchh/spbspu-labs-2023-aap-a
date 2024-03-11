#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstddef>
#include <istream>

#include "shape.hpp"

namespace vyzhanov
{
  void doScale(Shape* shape, const point_t& point, const double ratio);
  void inputShapes(Shape** shapes, point_t& point, double& ratio, size_t& length, std::istream& input);
  void deleteShapes(Shape* shapes[], size_t length);
}

#endif
