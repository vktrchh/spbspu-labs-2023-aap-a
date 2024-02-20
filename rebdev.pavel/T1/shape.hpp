#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace rebdev
{
  class Shape
  {
    public:
    virtual ~Shape() = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & point) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
  };
}

#endif
