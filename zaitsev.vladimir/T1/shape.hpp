#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace zaitsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& dest_pos) = 0;
    virtual void move(double x_shift, double y_shift) = 0;
    virtual void scale(double factor) = 0;
    virtual Shape* clone() const = 0;
  };
}
#endif
