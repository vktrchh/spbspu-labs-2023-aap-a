#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "baseTypes.hpp"

namespace agarkov
{
  class Square: public Shape
  {
  public:
    Square(point_t left_bottom, double length);
    double getArea() const override;
    rectangle_t getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectRectangle();
    point_t left_bottom_;
    point_t right_top_;
  };
}

#endif
