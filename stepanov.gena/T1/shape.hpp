#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace stepanov
{
  class Shape
  {
  public:
    double getArea();
    rectangle_t getFrameRect();
    void move();
    void scale();
  };
}

#endif
