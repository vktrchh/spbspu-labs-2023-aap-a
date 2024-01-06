#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & leftCorner, const point_t rightCorner);
    virtual ~Rectangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
  private:
    point_t leftCorner_;
    point_t rightCorner_;
  }
}

#endif
