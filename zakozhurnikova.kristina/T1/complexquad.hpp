#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
#include "geometryFunc.hpp"
#include <stdexcept>

namespace zakozhurnikova
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);

  private:
    point_t vertexes_[4];
    void doScale(double k);
  };
}
#endif

