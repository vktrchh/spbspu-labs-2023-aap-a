#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(point_t bias) = 0;
  virtual void move(const double dx, const double dy) = 0;
  virtual void scale(double coefficient) = 0;
};

#endif
