#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t point1, point_t point2, point_t point3);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual rectangle_t scale(point_t s, double k);
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    double height_tri_;
    double width_tri_;
    point_t pos_tri_;
    point_t pos_;
  };
}

#endif
