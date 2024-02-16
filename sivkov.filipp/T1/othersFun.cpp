#include "base-types.hpp"
#include "shape.hpp"
#include "othersFun.hpp"
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

  bool isInsideTriangle(const point_t& A, const point_t& B, const point_t& C, const point_t& D)
  {
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
}
