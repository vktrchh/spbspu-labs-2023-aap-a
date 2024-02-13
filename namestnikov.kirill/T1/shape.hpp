#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.hpp"

namespace namestnikov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual point_t getCenter() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & p) = 0;
    virtual void move(const double dx, const double dy) = 0;
    void scale(const double coefficient);
    virtual ~Shape() = default;
  private:
    virtual void doScale(const double coefficient) = 0;
  };
}

#endif
