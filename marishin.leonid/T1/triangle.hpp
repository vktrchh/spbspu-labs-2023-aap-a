#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace marishin
{
  class Triangle : public Shape
  {
  public:
    Triangle(const point_t &firstPoint, const point_t &secondPoint, const point_t &thirdPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &newPos);
    virtual void move(double dx, double dy);
    virtual void scale(double factor);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
