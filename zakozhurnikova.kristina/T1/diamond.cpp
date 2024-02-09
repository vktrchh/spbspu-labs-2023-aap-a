#include "diamond.hpp"
#include <cmath>

double zakozhurnikova::Diamond::getArea() const
{
  double d1 = 2 * pointOne_.getDistance(center_);
  double d2 = 2 * pointTwo_.getDistance(center_);
  return 0.5 * d1 * d2;
}

zakozhurnikova::rectangle_t zakozhurnikova::Diamond::getFrameRect() const
{
  double widthDist = std::abs(pointOne_.x - center_.x);
  double heightDist = std::abs(pointOne_.y - center_.y);
  double width = widthDist != 0 ? widthDist : std::abs(pointTwo_.x - center_.x);
  double height = heightDist != 0 ? heightDist : std::abs(pointTwo_.y - center_.y);
  return zakozhurnikova::rectangle_t(width, height, center_);
}

void zakozhurnikova::Diamond::move(double dx, double dy)
{
  zakozhurnikova::point_t shift(dx, dy);
  pointOne_ += shift;
  pointTwo_ += shift;
  center_ += shift;
}

void zakozhurnikova::Diamond::move(const point_t& p)
{
  double shiftX = p.x - center_.x;
  double shiftY = p.y - center_.y;
  move(shiftX,  shiftY);
}


void zakozhurnikova::Diamond::scale(double k)
{
  pointOne_ = center_ - (center_ - pointOne_) * k;
  pointTwo_ = center_ - (center_ - pointTwo_) * k;
}
