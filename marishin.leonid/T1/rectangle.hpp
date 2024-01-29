#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace marishin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t lowerLeftCorner, point_t topRightCorner);
    virtual ~Rectangle();
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t newPos);
    virtual void move(double dx, double dy);
    virtual void scale(double factor);
  private:
    point_t lowerLeftCorner_;
    point_t topRightCorner_;
  };
}

#endif
