#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace zakozhurnikova
{
  class Complexquad : public Shape
  {
  public:
    Complexquad() = delete;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    point_t p4_;
  };
}
#endif

