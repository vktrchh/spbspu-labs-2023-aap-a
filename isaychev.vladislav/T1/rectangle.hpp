#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace isaychev
{
  class Rectangle: public Shape
  {
   public:
    Rectangle(const point_t & p1, const point_t & p2);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newPos);
    virtual void move(const double dX, const double dY);
    virtual void scale(const double coeff);

   private:
    point_t botL_;
    point_t topR_;
  };
}

#endif
