#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "base-types.hpp"
namespace lopatina
{
  class Square: public Shape
  {
  public:
    Square(point_t a, double side);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t s);
    virtual void move(double x, double y);
    virtual rectangle_t scale(point_t s, double k);
  private:
    double side_;
    point_t pos_sq_;
  };
}

#endif
