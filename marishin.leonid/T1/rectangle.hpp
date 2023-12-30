#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t* lowerLeftCorner, const point_t* topRightCorner);
  virtual ~Rectangle() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t* newPos) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void scale(double factor) = 0;
private:
  double width;
  double height;
};

#endif
