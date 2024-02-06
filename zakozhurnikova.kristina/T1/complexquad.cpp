#include "complexquad.hpp"
#include <cmath>
#include <stdexcept>

double zakozhurnikova::Complexquad::getArea() const
{
  zakozhurnikova::point_t center = getCenter();

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
  double x1 = p1_.getX();
  double y1 = p1_.getY();
  double x2 = p2_.getX();
  double y2 = p2_.getY();
  double x3 = p3_.getX();
  double y3 = p3_.getY();
  double x4 = p4_.getX();
  double y4 = p4_.getY();
  double minX = std::fmin(std::fmin(x1, x2), std::fmin(x3, x4));
  double minY = std::fmin(std::fmin(y1, y2), std::fmin(y3, y4));
  double maxX = std::fmax(std::fmax(x1, x2), std::fmax(x3, x4));
  double maxY = std::fmax(std::fmax(y1, y2), std::fmax(y3, y4));
  double width = maxX - minX;
  double heihgt = maxY - maxY;
  point_t center((maxX + minX) / 2.0, (maxY + minY) / 2.0);
  return zakozhurnikova::rectangle_t(width, heihgt, center);
}

void zakozhurnikova::Complexquad::move(const point_t& p)
{
  zakozhurnikova::point_t center = getCenter();
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
  zakozhurnikova::point_t center = getCenter();
  p1_ = p1_.scaleShift(k, center);
  p2_ = p2_.scaleShift(k, center);
  p3_ = p3_.scaleShift(k, center);
  p4_ = p4_.scaleShift(k, center);
}

zakozhurnikova::point_t zakozhurnikova::Complexquad::getCenter() const
{
  double x1 = p1_.getX();
  double y1 = p1_.getY();
  double x2 = p2_.getX();
  double y2 = p2_.getY();
  double x3 = p3_.getX();
  double y3 = p3_.getY();
  double x4 = p4_.getX();
  double y4 = p4_.getY();
  double determinant = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
  double determinantX = (x2 - x1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (x4 - x3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  double determinantY = (y2 - y1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (y4 - y3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  return zakozhurnikova::point_t(determinantX / determinant, determinantY / determinant);
}

