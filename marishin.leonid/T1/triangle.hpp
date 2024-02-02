#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace marishin
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t newPos);
    virtual void move(double dx, double dy);
    virtual void scale(double factor);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
