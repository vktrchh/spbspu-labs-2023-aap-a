#include "base-types.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

void outputFrameRectInfo(std::ostream& out, const Shape* shape)
{
  out << " ";
  out << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2 << " ";
  out << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2 << " ";
  out << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2 << " ";
  out << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2 << "\n";
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
