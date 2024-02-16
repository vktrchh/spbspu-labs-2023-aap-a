#include "diamond.hpp"
#include "geometryFunc.hpp"
#include <cmath>

zakozhurnikova::Diamond::Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree) :
  pointOne_(pointOne),
  pointTwo_(pointTwo),
  center_(pointThree)
{
  point_t points[3];
  initPoints(points, pointOne, pointTwo, pointThree);
  center_ = points[0];
  pointOne_ = points[1];
  pointTwo_ = points[2];
  const bool CONDITION = ((std::abs(center_.x - pointOne_.x) == 0.0) && (std::abs(center_.y - pointTwo_.y) == 0.0)) ||
    ((std::abs(center_.x - pointTwo_.x) == 0.0) && (std::abs(center_.y - pointOne_.y) == 0.0));
  if (!CONDITION)
  {
    throw std::invalid_argument("These points do not define a diamond");
  }
}


double zakozhurnikova::Diamond::getArea() const
{
  double d1 = 2 * getDistance(pointOne_, center_);
  double d2 = 2 * getDistance(pointTwo_, center_);
  return 0.5 * d1 * d2;
}

zakozhurnikova::rectangle_t zakozhurnikova::Diamond::getFrameRect() const
{
  double width = std::abs(pointOne_.x - center_.x) * 2;
  double height = std::abs(pointTwo_.y - center_.y) * 2;
  if (width <= 1e-6)
  {
    width = std::abs(pointTwo_.x - center_.x) * 2;
    height = std::abs(pointOne_.y - center_.y) * 2;
  }
  return rectangle_t{width, height, center_};
}

void zakozhurnikova::Diamond::move(double dx, double dy)
{
  point_t shift = {dx, dy};
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


void zakozhurnikova::Diamond::doScale(double k)
{
  pointOne_ = center_ - (center_ - pointOne_) * k;
  pointTwo_ = center_ - (center_ - pointTwo_) * k;
}
