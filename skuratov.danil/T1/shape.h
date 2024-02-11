#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.h"

namespace skuratov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& A) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double B) = 0;
    virtual ~Shape() = default;
  };
}

#endif
