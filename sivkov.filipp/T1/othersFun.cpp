#include "base-types.hpp"
#include "shape.hpp"
#include "othersFun.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

namespace sivkov
{
  void outputFrameRectInfo(std::ostream& out, const Shape* shape)
  {
    out << " ";
    out << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2 << " ";
    out << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2 << " ";
    out << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2 << " ";
    out << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2 << "";
  }

  void findCoefficient(double& a, double& b, double& c, const point_t ver1, const point_t ver2)
  {
    if (ver1.x == ver2.x)
    {
      a = 1;
      b = 0;
      c = -ver2.x;
    }
    else if (ver1.y == ver2.y)
    {
      a = 0;
      b = 1;
      c = -ver2.y;
    }
    else
    {
      a = 1;
      b = (ver2.x - ver1.x) / (ver1.y - ver2.y);
      c = -ver1.x * a - ver1.y * b;
    }
  }

  double findLine(const point_t& a, const point_t& b)
  {
    return std::sqrt(std::abs(a.x - b.x) * std::abs(a.x - b.x) + std::abs(a.y - b.y) * std::abs(a.y - b.y));
  }
  bool isTriangle(point_t first, point_t second, point_t third)
  {
    bool is = (((third.x - first.x) / (second.x - first.x)) != ((third.y - first.y) / (second.y - first.y)));
    return is;
  }

  bool isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& D) {
    double ab = (B.y - A.y) * D.x + (A.x - B.x) * D.y + (B.x * A.y - A.x * B.y);
    double bc = (B.y - C.y) * D.x + (C.x - B.x) * D.y + (B.x * C.y - C.x * B.y);
    double ac = (C.y - A.y) * D.x + (A.x - C.x) * D.y + (C.x * A.y - A.x * C.y);
    return (ab < 0 && bc > 0 && ac > 0);
  }

  void scale(Shape* shape, point_t center, double k)
  {
    if (k < 0)
    {
      throw std::invalid_argument("K cannot be < 0");
    }
    point_t pos = shape->getFrameRect().pos;
    shape->move(center);
    point_t newPos = shape->getFrameRect().pos;
    shape->scale(k);
    shape->move(k * (pos.x - newPos.x), k * (pos.y - newPos.y));
  }
  point_t findCenter(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4)
  {
    double a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;

    findCoefficient(a1, b1, c1, ver1, ver2);
    findCoefficient(a2, b2, c2, ver3, ver4);

    if (a1 / a2 == b1 / b2)
    {
      throw std::invalid_argument("no intersection");
    }
    else {
      double x = 0, y = 0;
      double dx = c2 * b1 - c1 * b2;
      double dy = c1 * a2 - a1 * c2;
      double d = a1 * b2 - b1 * a2;
      x = dx / d;
      y = dy / d;
      return { x, y };
    }
  }

  bool areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4)
  {
    double line1x = ver2.x - ver1.x;
    double line1y = ver2.y - ver1.y;
    double line2x = ver3.x - ver1.x;
    double line2y = ver3.y - ver1.y;
    double line3x = ver4.x - ver1.x;
    double line3y = ver4.y - ver1.y;

    bool check1 = ((line1x * line2y - line1y * line2x) * (line1x * line3y - line1y * line3x) < 0);

    line1x = ver4.x - ver3.x;
    line1y = ver4.y - ver3.y;
    line2x = ver1.x - ver3.x;
    line2y = ver1.y - ver3.y;
    line3x = ver2.x - ver3.x;
    line3y = ver2.y - ver3.y;

    bool check2 = ((line1x * line2y - line1y * line2x) * (line1x * line3y - line1y * line3x) < 0);
    return check1 && check2;
  }
}
