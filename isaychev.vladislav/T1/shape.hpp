#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace isaychev
{
  class Shape
  {
   public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & newPos) = 0;
    virtual void move(const double dX, const double dY) = 0;
    virtual void scale(const double coeff) = 0;
  };
}

#endif
