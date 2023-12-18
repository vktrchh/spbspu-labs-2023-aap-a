#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.hpp"
class Shape
{
  public:
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t);
  virtual void move(double);
  virtual void scale(double);
};

#endif
