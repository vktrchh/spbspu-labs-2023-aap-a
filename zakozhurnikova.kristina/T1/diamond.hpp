#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
#include "geometryFunc.hpp"
#include <limits>
#include <stdexcept>

namespace zakozhurnikova
{
  class Diamond: public Shape
  {
  public:
    Diamond() = delete;
    Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void scale(double k);
  private:
    point_t pointOne_;
    point_t pointTwo_;
    point_t center_;
  };
}
#endif
