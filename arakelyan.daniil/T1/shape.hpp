#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

struct Shape
{
  virtual double getArea() const = 0;
  virtual point_t getFrameRect() = 0;
  virtual void move(point_t) = 0;
  virtual void move(double) = 0;
  virtual void move(double, double) = 0;
  virtual void scale(double) = 0;
  virtual ~Shape() = default;
};

#endif
