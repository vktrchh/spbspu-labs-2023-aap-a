#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
namespace piyavkin
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& bias) override;
    void move(double dx, double dy) override;
  private:
    point_t lowerLeftCorner_;
    point_t topRightCorner_;
    void scaleFigure(double k) override;
  };
}
#endif
