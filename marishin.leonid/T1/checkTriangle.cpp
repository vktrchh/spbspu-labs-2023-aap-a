#include "checkTriangle.hpp"
#include <cmath>
#include <stdexcept>

void marishin::checkTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_)
{
  double ab = std::sqrt((firstPoint_.x - secondPoint_.x) * (firstPoint_.x - secondPoint_.x)
    + (firstPoint_.y - secondPoint_.y) * (firstPoint_.y - secondPoint_.y));
  double ac = std::sqrt((firstPoint_.x - thirdPoint_.x) * (firstPoint_.x - thirdPoint_.x)
    + (firstPoint_.y - thirdPoint_.y) * (firstPoint_.y - thirdPoint_.y));
  double bc = std::sqrt((secondPoint_.x - thirdPoint_.x) * (secondPoint_.x - thirdPoint_.x)
    + (secondPoint_.y - thirdPoint_.y) * (secondPoint_.y - thirdPoint_.y));
  if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
  {
    throw std::invalid_argument("Irregular triangle");
  }
}

double marishin::getAreaTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_)
{
  double ab_ = std::sqrt((firstPoint_.x - secondPoint_.x) * (firstPoint_.x - secondPoint_.x)
    + (firstPoint_.y - secondPoint_.y) * (firstPoint_.y - secondPoint_.y));
  double ac_ = std::sqrt((firstPoint_.x - thirdPoint_.x) * (firstPoint_.x - thirdPoint_.x)
    + (firstPoint_.y - thirdPoint_.y) * (firstPoint_.y - thirdPoint_.y));
  double bc_ = std::sqrt((secondPoint_.x - thirdPoint_.x) * (secondPoint_.x - thirdPoint_.x)
    + (secondPoint_.y - thirdPoint_.y) * (secondPoint_.y - thirdPoint_.y));
  double abc = (ab_ + bc_ + ac_) / 2;
  return std::sqrt(abc * (abc - ab_) * (abc - bc_) * (abc - ac_));
}

point_t marishin::getFrameRectTriangle(const point_t& firstPoint_, const point_t& secondPoint_, const point_t& thirdPoint_)
{
  double height = (std::max(firstPoint_.y, (std::max(secondPoint_.y, thirdPoint_.y)))
    - (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))));
  double width = (std::max(firstPoint_.x, (std::max(secondPoint_.x, thirdPoint_.x)))
    - (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))));
  point_t pos = { (std::min(firstPoint_.x, (std::min(secondPoint_.x, thirdPoint_.x)))) + width / 2,
    (std::min(firstPoint_.y, (std::min(secondPoint_.y, thirdPoint_.y)))) + height / 2  };
  return { pos, width, height };
}
