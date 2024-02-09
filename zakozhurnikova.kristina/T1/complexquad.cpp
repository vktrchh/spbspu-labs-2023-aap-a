#include <cmath>
#include "complexquad.hpp"
#include <stdexcept>

double zakozhurnikova::Complexquad::getArea() const
{
  point_t points[4] {p1_, p2_, p3_, p4_};
  zakozhurnikova::point_t center = getComplexquadCenter(points);

  double a1 = p1_.getDistance(center);
  double b1 = p4_.getDistance(center);
  double c1 = p1_.getDistance(p4_);
  double s1 = (a1 + b1 + c1) / 2.0;
  double area1 = std::sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));

  double a2 = p2_.getDistance(center);
  double b2 = p3_.getDistance(center);
  double c2 = p2_.getDistance(p3_);
  double s2 = (a2 + b2 + c2) / 2.0;
  double area2 = std::sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));

  return area1 + area2;
}

zakozhurnikova::rectangle_t zakozhurnikova::Complexquad::getFrameRect() const
{
  double x1 = p1_.x;
  double y1 = p1_.y;
  double x2 = p2_.x;
  double y2 = p2_.y;
  double x3 = p3_.x;
  double y3 = p3_.y;
  double x4 = p4_.x;
  double y4 = p4_.y;
  double minX = std::min(std::min(x1, x2), std::min(x3, x4));
  double minY = std::min(std::min(y1, y2), std::min(y3, y4));
  double maxX = std::max(std::max(x1, x2), std::max(x3, x4));
  double maxY = std::max(std::max(y1, y2), std::max(y3, y4));
  double width = maxX - minX;
  double height = maxY - maxY;
  point_t center((maxX + minX) / 2.0, (maxY + minY) / 2.0);
  return zakozhurnikova::rectangle_t(width, height, center);
}

void zakozhurnikova::Complexquad::move(const point_t& p)
{
  point_t points[4] {p1_, p2_, p3_, p4_};
  zakozhurnikova::point_t center = getComplexquadCenter(points);
  zakozhurnikova::point_t shift(-(center - p));
  p1_ += shift;
  p2_ += shift;
  p3_ += shift;
  p4_ += shift;
}

void zakozhurnikova::Complexquad::move(double dx, double dy)
{
  p1_ += zakozhurnikova::point_t(dx, dy);
  p2_ += zakozhurnikova::point_t(dx, dy);
  p3_ += zakozhurnikova::point_t(dx, dy);
  p4_ += zakozhurnikova::point_t(dx, dy);
}

void zakozhurnikova::Complexquad::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Scale coefficient should be a positive real number.");
  }
  point_t points[4] {p1_, p2_, p3_, p4_};
  zakozhurnikova::point_t center = getComplexquadCenter(points);
  p1_ = p1_.scaleShift(k, center);
  p2_ = p2_.scaleShift(k, center);
  p3_ = p3_.scaleShift(k, center);
  p4_ = p4_.scaleShift(k, center);
}
