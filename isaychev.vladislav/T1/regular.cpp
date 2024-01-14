#include "regular.hpp"
#include <cmath>
//#include <limits>

isaychev::Regular::Regular(const point_t & p1, const point_t & p2, const point_t & p3):
  center_(p1),
  closePnt_(p2),
  distPnt_(p3)
{}

double isaychev::Regular::getArea() const
{
  double inRad = 0.0, bottom = 0.0, radX = 0.0, radY = 0.0;
  radX = (distPnt_.x_ - closePnt_.x_) * (distPnt_.x_ - closePnt_.x_);
  radY = (distPnt_.y_ - closePnt_.y_) * (distPnt_.y_ - closePnt_.y_);
  bottom = std::sqrt(radX + radY);
  radX = (center_.x_ - closePnt_.x_) * (center_.x_ - closePnt_.x_);
  radY = (center_.y_ - closePnt_.y_) * (center_.y_ - closePnt_.y_);
  inRad = std::sqrt(radX + radY);
  double numOfSides = 3.1415926535 / std::atan(bottom / inRad);
  return bottom * inRad * numOfSides;
}

isaychev::rectangle_t isaychev::Regular::getFrameRect() const
{
  double radX = 0, radY = 0;
  radX = (center_.x_ - closePnt_.x_) * (center_.x_ - closePnt_.x_);
  radY = (center_.y_ - closePnt_.y_) * (center_.y_ - closePnt_.y_);
  double leg = std::sqrt(radX + radY);
  radX = (distPnt_.x_ - center_.x_);
  radY = (distPnt_.y_ - center_.y_);
  double outRad = std::sqrt(radX * radX + radY * radY);
  double initXAngle = std::acos(radX / outRad);
  double steerAngle = 2 * std::acos(leg / outRad);
  double numOfSides = std::round(3.1415926535 / std::acos(leg / outRad));
  double minX = 0.0, minY = 0.0, maxX = 0.0, maxY = 0.0;
  minX = maxX = distPnt_.x_;
  minY = maxY = distPnt_.y_;
  for (double i = 1.0; i < numOfSides; i++)
  {
    double currX = center_.x_ + outRad * cos(initXAngle + i * steerAngle);
    if (currX < minX)
    {
      minX = currX;
    }
    if (currX > maxX)
    {
      maxX = currX;
    }
    double currY = center_.y_ + outRad * sin(initXAngle + i * steerAngle);
    if (currY < minY)
    {
      minY = currY;
    }
    if (currY > maxY)
    {
      maxY = currY;
    }
  }
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = {minX + (width / 2), minY + (height / 2)};
  return {width, height, pos};
}

void isaychev::Regular::move(const double dX, const double dY)
{
  center_.x_ += dX;
  closePnt_.x_ += dX;
  distPnt_.x_ += dX;
  center_.y_ += dY;
  closePnt_.y_ += dY;
  distPnt_.y_ += dY;
}

void isaychev::Regular::move(const point_t & newPos)
{
  double dX = newPos.x_ - center_.x_;
  closePnt_.x_ += dX;
  distPnt_.x_ += dX;
  double dY = newPos.y_ - center_.y_;
  closePnt_.y_ += dY;
  distPnt_.y_ += dY;
  center_ = {newPos.x_, newPos.y_};
}

void isaychev::Regular::scale(const double coeff)
{
  double coordCoeff = 0.0;
  if (coeff > 1.0)
  {
    coordCoeff = std::sqrt(coeff - 1);
  }
  else
  {
    coordCoeff = std::sqrt(1 - coeff);
  }
  distPnt_.x_ *= coordCoeff;
  closePnt_.x_ *= coordCoeff;
  distPnt_.y_ *= coordCoeff;
  closePnt_.y_ *= coordCoeff;
}
