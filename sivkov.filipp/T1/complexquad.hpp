#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include "shape.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <cmath>
#include <cstddef>

class Complexquad : public Shape
{
public:
  Complexquad(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect() const;
  virtual void move(point_t newPos);
  virtual void move(double x, double y);
  virtual void scale(double k);
  double areaOfTriangle(const point_t& ver1, const point_t& ver2, const point_t& ver3) const;
  bool areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
  point_t findIntersection(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4) const;
private:
  point_t cqVer1_;
  point_t cqVer2_;
  point_t cqVer3_;
  point_t cqVer4_;
};

#endif

