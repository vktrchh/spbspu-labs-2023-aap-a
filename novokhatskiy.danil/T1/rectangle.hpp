#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace novokhatskiy
{
  class Rectangle: public Shape
  {

  public:
    Rectangle(const point_t &lowerLeftCorner, const point_t &upperRightCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &p);
    virtual void move(double x, double y);
    virtual void scale(double ratio);

  private:
    point_t lowerLeftCorner_;
    point_t upperRightCorner_;
  };
}

#endif
