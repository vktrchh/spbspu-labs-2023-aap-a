#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace isaychev
{
  class Rectangle: public Shape
  {
   public:
    virtual double getArea() const;
    virtual rectangle_t & getFrameRect() const;
    virtual void move(point_t & newPos);
    virtual void move(double dX, double dY);
    virtual void scale(double x, double y, double coeff);
  };
}

#endif
