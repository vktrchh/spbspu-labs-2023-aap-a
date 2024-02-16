#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include <stdexcept>

namespace zakozhurnikova
{

  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& pointOne, const point_t& pointTwo);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);

  private:
    point_t downLeft_;
    point_t upRight_;
    void doScale(double k);
  };
}
#endif
