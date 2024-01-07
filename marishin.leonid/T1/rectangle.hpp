#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t lowerLeftCorner, const point_t topRightCorner);
  virtual ~Rectangle();
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(const point_t newPos);
  virtual void move(const double dx, const double dy);
  virtual void scale(const double factor);
private:
  double width;
  double height;
};

#endif
