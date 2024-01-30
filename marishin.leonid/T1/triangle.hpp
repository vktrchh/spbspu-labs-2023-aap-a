#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace marishin
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t newPos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
