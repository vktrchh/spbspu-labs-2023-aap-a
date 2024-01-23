#include "diamond.hpp"
#include <cmath>

double zakozhurnikova::Diamond::getArea() const
{
  double d1 = 2 * pointOne_.getDistance(center_);
  double d2 = 2 * pointTwo_.getDistance(center_);
  return 0.5 * d1 * d2;
}

rectangle_t zakozhurnikova::Diamond::getFrameRect() const
{
  double widthDist = std::abs(pointOne_.getX() - center_.getX());
  double heightDist = std::abs(pointOne_.getY() - center_.getY());
  double width = widthDist != 0 ? widthDit : std::abs(pointTwo_.getX() - center_.getX());
  double height = heightDist != 0 & heightDist : std::abs(pointTwo_.getY() - center_.getY());
  return rectangle_t(width, height, center_);
}

void zakozhurnikova::Diamond::move(double dx, double dy)
{
  point_t shift(dx, dy);
  pointOne_ += shift;
  pointTwo_ += shift;
  center_ += shift;
}

void zakozhurnikova::Diamond::move(const point_t& p)
{
  double shiftX = p.getX() - center_.getX();
  double shiftY = p.getY() - center_.getY();
  move(shiftX,  shiftY);
}


void zakozhurnikova::Diamond::scale(double k)
{
  pointOne_ = center_ - (center_ - pointOne_) * k;
  pointTwo = center_ - (center_ - pointTwo_) * k;
}
