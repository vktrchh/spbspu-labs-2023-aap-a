#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& left_corner, const point_t& right_corner);
    Rectangle(const Rectangle& other) = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void scale(double factor);
    virtual Shape* clone() const;
  private:
    point_t left_corner_;
    point_t right_corner_;
    point_t getCenter() const;
  };
}
#endif
