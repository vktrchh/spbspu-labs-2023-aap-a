#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace vyzhanov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& leftCorner, const point_t& rightCorner);
    virtual ~Rectangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    point_t leftCorner_;
    point_t rightCorner_;
  };
}
#endif
