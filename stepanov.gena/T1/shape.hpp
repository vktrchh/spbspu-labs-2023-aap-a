#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace stepanov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move() = 0;
    virtual void scale() = 0;
  };
}

#endif
