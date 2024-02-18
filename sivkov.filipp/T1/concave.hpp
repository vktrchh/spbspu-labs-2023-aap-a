#ifndef concave_hpp
#define concave_hpp

#include "shape.hpp"

namespace sivkov
{
  class Concave: public Shape
  {
  public:
    Concave(const point_t cvVer1, const point_t cvVer2, const point_t cvVer3, const point_t cvVer4);
    ~Concave();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t newPos);
    void move(double x, double y);
    void scale(double k);
  private:
    point_t cvVer1_;
    point_t cvVer2_;
    point_t cvVer3_;
    point_t cvVer4_;
  };
}

#endif
