#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
#include <stdexcept>

namespace arakelyan
{
  struct Shape
  {
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t) = 0;
    virtual void move(double, double) = 0;
    virtual void scaleShape(double);
    virtual ~Shape() = default;
    private:
    virtual void scale(double k)
    {
      if (k < 0.0)
      {
        throw std::logic_error("k cannot be less than zero!");
      }
    };
  };
}
#endif
