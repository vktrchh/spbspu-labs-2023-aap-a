#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>

namespace sivkov
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t newPos);
    void move(double x, double y);
    void scale(double k);
    bool areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
    point_t findCenter(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4) const;
  private:
    point_t cqVer1_;
    point_t cqVer2_;
    point_t cqVer3_;
    point_t cqVer4_;
  };
}

#endif

