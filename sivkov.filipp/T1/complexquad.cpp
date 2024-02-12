#include "complexquad.hpp"
#include <stdexcept>

Complexquad::Complexquad(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4) :
  cqVer1_(ver1),
  cqVer2_(ver2),
  cqVer3_(ver3),
  cqVer4_(ver4)
{
  if (!areSegmentsIntersecting(ver1, ver2, ver3, ver4)) 
  {
    throw std::invalid_argument("Sides of the complex quad intersect. Invalid configuration.");
  }
}

double Complexquad::getArea() const
{
  point_t center = findIntersection(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  double area1 = areaOfTriangle(cqVer1_, cqVer4_, center);
  double area2 = areaOfTriangle(cqVer2_, cqVer3_, center);
  return area1 + area2;
}

rectangle_t Complexquad::getFrameRect() const
{
  double xmin = cqVer1_.x;
  double ymin = cqVer1_.y;
  double xmax = cqVer1_.x;
  double ymax = cqVer1_.y;
  if (cqVer2_.x < xmin) xmin = cqVer2_.x;
  if (cqVer2_.x > xmax) xmax = cqVer2_.x;
  if (cqVer2_.y < ymin) ymin = cqVer2_.y;
  if (cqVer2_.y > ymax) ymax = cqVer2_.y;

  if (cqVer3_.x < xmin) xmin = cqVer3_.x;
  if (cqVer3_.x > xmax) xmax = cqVer3_.x;
  if (cqVer3_.y < ymin) ymin = cqVer3_.y;
  if (cqVer3_.y > ymax) ymax = cqVer3_.y;

  if (cqVer4_.x < xmin) xmin = cqVer4_.x;
  if (cqVer4_.x > xmax) xmax = cqVer4_.x;
  if (cqVer4_.y < ymin) ymin = cqVer4_.y;
  if (cqVer4_.y > ymax) ymax = cqVer4_.y;

  return rectangle_t{ point_t{xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2} ,(xmax - xmin), (ymax - ymin) };
}

void Complexquad::move(point_t newPos)
{
  point_t center = findIntersection(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  const double dx = newPos.x - center.x;
  const double dy = newPos.y - center.y;
  move(dx, dy);
}

void Complexquad::move(const double dx, const double dy)
{
  cqVer1_.x += dx;
  cqVer1_.y += dy;
  cqVer2_.x += dx;
  cqVer2_.y += dy;
  cqVer3_.x += dx;
  cqVer3_.y += dy;
  cqVer4_.x += dx;
  cqVer4_.y += dy;
}

void Complexquad::scale(const double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must be > 0\n");
  }
  else
  {
    point_t centerPoint = findIntersection(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
    cqVer1_.x = centerPoint.x + (cqVer1_.x - centerPoint.x) * k;
    cqVer1_.y = centerPoint.y + (cqVer1_.y - centerPoint.y) * k;
    cqVer2_.x = centerPoint.x + (cqVer2_.x - centerPoint.x) * k;
    cqVer2_.y = centerPoint.y + (cqVer2_.y - centerPoint.y) * k;
    cqVer3_.x = centerPoint.x + (cqVer3_.x - centerPoint.x) * k;
    cqVer3_.y = centerPoint.y + (cqVer3_.y - centerPoint.y) * k;
    cqVer4_.x = centerPoint.x + (cqVer4_.x - centerPoint.x) * k;
    cqVer4_.y = centerPoint.y + (cqVer4_.y - centerPoint.y) * k;
  }
}

double Complexquad::areaOfTriangle(const point_t& ver1, const point_t& ver2, const point_t& ver3) const
{
  double a = std::sqrt(std::abs(ver1.x - ver2.x) * std::abs(ver1.x - ver2.x) + std::abs(ver1.y - ver2.y) * std::abs(ver1.y - ver2.y));
  double b = std::sqrt(std::abs(ver1.x - ver3.x) * std::abs(ver1.x - ver3.x) + std::abs(ver1.y - ver3.y) * std::abs(ver1.y - ver3.y));
  double c = std::sqrt(std::abs(ver2.x - ver3.x) * std::abs(ver2.x - ver3.x) + std::abs(ver2.y - ver3.y) * std::abs(ver2.y - ver3.y));
  double halfPerimetr = (a + b + c) / 2;
  double area = std::sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
  return area;
}

point_t Complexquad::findIntersection(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4) const
{
  double a1, b1, c1, a2, b2, c2;

  if (ver1.x == ver2.x)
  {
    a1 = 1;
    b1 = 0;
    c1 = -ver2.x;
  }
  else if (ver1.y == ver2.y)
  {
    a1 = 0;
    b1 = 1;
    c1 = -ver2.y;
  }
  else {
    a1 = 1;
    b1 = (ver2.x - ver1.x) / (ver1.y - ver2.y);
    c1 = -ver1.x * a1 - ver1.y * b1;
  }
  if (ver3.x == ver4.x) {
    a2 = 1;
    b2 = 0;
    c2 = -ver4.x;
  }
  else if (ver3.y == ver4.y)
  {
    a2 = 0;
    b2 = 1;
    c2 = -ver4.y;
  }
  else {
    a2 = 1;
    b2 = (ver4.x - ver3.x) / (ver3.y - ver4.y);
    c2 = -ver3.x * a2 - ver3.y * b2;
  }

  if (a1 / a2 == b1 / b2)
  {
    throw std::invalid_argument("no intersection\n");
  }
  else {
    double x = 0, y = 0;
    double d = a1 * b2 - b1 * a2;
    double dx = c2 * b1 - c1 * b2;
    double dy = c1 * a2 - a1 * c2;
    x = dx / d;
    y = dy / d;
    return { x, y };
  }
}

bool Complexquad::areSegmentsIntersecting(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4)
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
  return check1 * check2;
}


