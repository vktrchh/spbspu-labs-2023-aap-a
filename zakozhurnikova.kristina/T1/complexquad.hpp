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
    Complexquad(const point_t vertexes[4]);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);

  private:
    point_t vertexes_[4];
  };
}
#endif

