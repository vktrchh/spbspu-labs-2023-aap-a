#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"

namespace namestnikov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & leftCornerPoint, const point_t & rightCornerPoint);
    virtual double getArea() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
    virtual point_t getCenter() const;
    virtual rectangle_t getFrameRect() const;
  private:
    point_t leftCornerPoint_;
    point_t rightCornerPoint_;
  };
}

#endif
