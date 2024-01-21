#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& leftTop, const point_t& rightBottom);
  virtual double getArea() const override;
  virtual rectangle_t getFrameRect() const override;
  virtual void move(const point_t& newPos) override;
  virtual void move(double dx, double dy) override;
  virtual void scale(double factor) override;

private:
  point_t leftTop_;
  point_t rightBottom_;
};

#endif
