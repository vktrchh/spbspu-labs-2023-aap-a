#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &leftTop, const point_t &rightBottom);
  virtual ~Rectangle();
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(const point_t &newPos);
  virtual void move(double dx, double dy);
  virtual void scale(double factor);

private:
  double leftTop_;
  double rightBottom_;
};

#endif
