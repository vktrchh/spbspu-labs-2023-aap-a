#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t a, point_t b);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual void scale(point_t s, double k);
  private:
    double height_rect_;
    double width_rect_;
    point_t pos_rect_;
  };
}

#endif
