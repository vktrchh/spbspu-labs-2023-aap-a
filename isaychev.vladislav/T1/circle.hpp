#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"

namespace isaychev
{
  class Circle: public Shape
  {
   public:
    Circle(const point_t p, const double rad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newPos);
    virtual void move(const double dX, const double dY);
    virtual void scale(const double coeff);

   private:
    point_t center_;
    double radius_;
  };
}

#endif
