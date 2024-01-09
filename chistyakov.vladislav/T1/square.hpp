#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Square : public Shape
  {
  public:
    Square(const point_t & leftCorner, const double side);
    virtual ~Square();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(const double mx, const double my);
    virtual void scale(const double ratio);
  private:
    point_t leftCorner_;
    double side_;
  };
}

#endif
