#ifndef OTHERSFUN_HPP
#define OTHERSFUN_HPP
#include "shape.hpp"
#include <iostream>

namespace sivkov
{
  void outputFrameRectInfo(std::ostream& out, const Shape* shape);
  void findCoefficient(double& a, double& b, double& c, const point_t ver1, const point_t ver2);
  double findLine(const point_t& a, const point_t& b);
  bool isTriangle(point_t first, point_t second, point_t third);
  bool isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& D);
  void scale(Shape* shape, point_t center, double k);
  bool areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
  point_t findCenter(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
}
#endif
