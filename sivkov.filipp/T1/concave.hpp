#ifndef concave_hpp
#define concave_hpp

#include "shape.hpp"

namespace sivkov
{
  class Concave : public Shape
  {
  public:
    Concave(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4);
    ~Concave();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t newPos);
    void move(double x, double y);
    void scale(double k);
  private:
    point_t ver1_;
    point_t ver2_;
    point_t ver3_;
    point_t ver4_;
  };
}

#endif
