#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

namespace namestnikov
{
  class Shape
  {
  public:
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
    virtual ~Shape() = default;
  };
}

#endif
