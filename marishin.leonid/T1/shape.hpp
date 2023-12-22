#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual double getArea(double a, double b) const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t* newPos);
  virtual void move(double dx, double dy);
  virtual void scale(double factor);
};

#endif
