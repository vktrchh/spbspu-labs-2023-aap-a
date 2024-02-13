#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace namestnikov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & leftCorner, const point_t & rightCorner);
    virtual double getArea() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual rectangle_t getFrameRect() const;
  private:
    point_t leftCorner_;
    point_t rightCorner_;
    point_t getCenter() const;
    virtual void scale(const double coefficient);
  };
}

#endif
