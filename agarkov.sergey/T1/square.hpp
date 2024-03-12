#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "baseTypes.hpp"

namespace agarkov
{
  class Square: public Shape
  {
  public:
    double getArea() const;
    rectangle_t getFrameRectangle() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(double k);
  private:
    point_t left_bottom_;
    double length;
  };
}

#endif
