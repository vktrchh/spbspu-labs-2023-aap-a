#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base-types.h"
#include "Shape.h"

namespace zaitsev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& left_ñorner, const point_t& right_ñorner);
    Rectangle(const Rectangle& rect);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void scale(double factor);
    point_t getCenter() const;
  private:
    point_t left_ñorner_;
    point_t right_ñorner_;
  };
}
#endif
