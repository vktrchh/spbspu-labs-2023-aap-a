#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace chistyakov
{
  class Shape
  {
    virtual ~Shape() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
  };
}

#endif
