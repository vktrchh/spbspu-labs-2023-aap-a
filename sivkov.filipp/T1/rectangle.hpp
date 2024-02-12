#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(point_t leftBotton, point_t rightTop);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t newPos);
  void move(double dx, double dy);
  void scale(double factor);

private:
  point_t leftBottom_;
  point_t rightTop_;
};

#endif
