#ifndef OTHERSFUN_HPP
#define OTHERSFUN_HPP
#include <iostream>
#include "shape.hpp"

namespace sivkov
{
  void outputFrameRectInfo(std::ostream& out, Shape* shape);
  void findCoefficient(double& a, double& b, double& c, point_t& ver1, point_t& ver2);
  double findLine(const point_t& a, const point_t& b);
  bool isTriangle(const point_t& first, const point_t& second, const point_t& third);
  bool isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& D);
  void scale(Shape* shape, point_t center, double k);
  point_t calculateVector(const point_t& p1, const point_t& p2);
  bool areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
  point_t findCenter(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4);
  point_t doCenterShift(double k, point_t center, point_t ver);
  point_t shift(point_t newXY, point_t ver);
  void readTops(std::istream& input, double tops[], size_t numberOfTops);
  void deleteMemory(Shape** shapes, size_t count);
}
#endif
