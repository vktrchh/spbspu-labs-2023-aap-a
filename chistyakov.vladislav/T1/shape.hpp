#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace chistyakov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & point) = 0;
    virtual void move(const double mx, const double my) = 0;
    virtual void scale(const double ratio) = 0;
  };
}

#endif
