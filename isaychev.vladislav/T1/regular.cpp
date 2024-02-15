#include "regular.hpp"
#include <stdexcept>
#include <cmath>

bool canBeReg(double a, double c)
{
  double a1 = 0.0, c1 = 0.0;
  a1 = std::min(a, c);
  c1 = std::max(a, c);
  double angle = std::acos(a1 / c1);
  double n = 3.1415926535 / angle;
  double roundedN = std::round(n);
  if (std::fabs(roundedN - n) < 0.0001)
  {
    return true;
  }
  return false;
}

bool isTriangle(double a, double b, double c)
{
  double a1 = std::sqrt(a);
  double b1 = std::sqrt(b);
  double c1 = std::sqrt(c);
  if (a1 + b1 > c1 && a1 + c1 > b1 && b1 + c1 > a1)
  {
    return true;
  }
  return false;
}

isaychev::Regular::Regular(const point_t & p1, const point_t & p2, const point_t & p3):
  center_(p1),
  closePnt_(p2),
  distPnt_(p3)
{
  double side1 = std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2);
  double side2 = std::pow((p1.x - p3.x), 2) + std::pow((p1.y - p3.y), 2);
  double bottom = std::pow((p2.x - p3.x), 2) + std::pow((p2.y - p3.y), 2);
  int regCheck = canBeReg(side1, side2);
  int triCheck = isTriangle(side1, side2, bottom);
  if (side2 == side1 + bottom && regCheck == 1 && triCheck == 1)
  {
    closePnt_.x = p2.x;
    closePnt_.y = p2.y;
    distPnt_.x = p3.x;
    distPnt_.y = p3.y;
  }
  else if (!(side1 == side2 + bottom) || regCheck == 0 || triCheck == 0)
  {
    throw std::logic_error("Incorrect regular parameters");
  }
}

double isaychev::Regular::getArea() const
{
  double inRad = 0.0, bottom = 0.0, radX = 0.0, radY = 0.0;
  radX = (distPnt_.x - closePnt_.x) * (distPnt_.x - closePnt_.x);
  radY = (distPnt_.y - closePnt_.y) * (distPnt_.y - closePnt_.y);
  bottom = std::sqrt(radX + radY);
  radX = (center_.x - closePnt_.x) * (center_.x - closePnt_.x);
  radY = (center_.y - closePnt_.y) * (center_.y - closePnt_.y);
  inRad = std::sqrt(radX + radY);
  int numOfSides = std::round(3.1415926535 / std::atan(bottom / inRad));
  return bottom * inRad * numOfSides;
}

isaychev::rectangle_t isaychev::Regular::getFrameRect() const
{
  double radX = 0.0, radY = 0.0;
  radX = (center_.x - closePnt_.x) * (center_.x - closePnt_.x);
  radY = (center_.y - closePnt_.y) * (center_.y - closePnt_.y);
  double leg = std::sqrt(radX + radY);
  radX = (distPnt_.x - center_.x);
  radY = (distPnt_.y - center_.y);
  double outRad = std::sqrt(radX * radX + radY * radY);
  double initXAngle = std::acos(radX / outRad);
  double steerAngle = 2 * std::acos(leg / outRad);
  size_t numOfSides = std::round(3.1415926535 / std::acos(leg / outRad));
  double minX = 0.0, minY = 0.0, maxX = 0.0, maxY = 0.0;
  minX = maxX = distPnt_.x;
  minY = maxY = distPnt_.y;
  for (size_t i = 1.0; i < numOfSides; i++)
  {
    double currX = center_.x + outRad * std::cos(initXAngle + i * steerAngle);
    if (currX < minX)
    {
      minX = currX;
    }
    if (currX > maxX)
    {
      maxX = currX;
    }
    double currY = center_.y + outRad * std::sin(initXAngle + i * steerAngle);
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

void isaychev::Regular::move(double dX, double dY)
{
  center_.x += dX;
  closePnt_.x += dX;
  distPnt_.x += dX;
  center_.y += dY;
  closePnt_.y += dY;
  distPnt_.y += dY;
}

void isaychev::Regular::move(const point_t & newPos)
{
  double dX = newPos.x - center_.x;
  closePnt_.x += dX;
  distPnt_.x += dX;
  double dY = newPos.y - center_.y;
  closePnt_.y += dY;
  distPnt_.y += dY;
  center_ = {newPos.x, newPos.y};
}

void isaychev::Regular::scale(double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("wrong coefficient for scale");
  }
  else
  {
    distPnt_.x = center_.x + (distPnt_.x - center_.x) * coeff;
    closePnt_.x = center_.x + (closePnt_.x - center_.x) * coeff;
    distPnt_.y = center_.y + (distPnt_.y - center_.y) * coeff;
    closePnt_.y = center_.y + (closePnt_.y - center_.y) * coeff;
  }
}
