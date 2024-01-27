#include "rectangle.hpp"
#include <iostream>

namespace piyavkin
{
  Rectangle::Rectangle(point_t p1, point_t p2):
    lowerLeftCorner_(p1),
    topRightCorner_(p2)
  {
    if (!(lowerLeftCorner_.x < topRightCorner_.x && lowerLeftCorner_.y < topRightCorner_.y))
    {
      throw std::logic_error("It is not rectangle");
    }
  }
  double Rectangle::getArea() const
  {
    return std::abs((lowerLeftCorner_.x - topRightCorner_.x) * (lowerLeftCorner_.y - topRightCorner_.y));
  }
  rectangle_t piyavkin::Rectangle::getFrameRect() const
  {
    point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
    return {std::abs(lowerLeftCorner_.x - topRightCorner_.x), std::abs(lowerLeftCorner_.y - topRightCorner_.y), pos};
  }
  void Rectangle::move(point_t bias)
  {
    point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
    move(bias.x - pos.x, bias.y - pos.y);
  }
  void Rectangle::move(double dx, double dy)
  {
    lowerLeftCorner_.x += dx;
    lowerLeftCorner_.y += dy;
    topRightCorner_.x += dx;
    topRightCorner_.y += dy;
  }
  void piyavkin::Rectangle::scale(double k)
  {
    point_t pos = {(lowerLeftCorner_.x + topRightCorner_.x) / 2, (lowerLeftCorner_.y + topRightCorner_.y) / 2};
    lowerLeftCorner_.x = k * (pos.x - lowerLeftCorner_.x) + pos.x;
    topRightCorner_.x = k * (pos.x - topRightCorner_.x) + pos.x;
    lowerLeftCorner_.y = k * (pos.y - lowerLeftCorner_.y) + pos.y;
    topRightCorner_.y = k * (pos.y - topRightCorner_.y) + pos.y;
  }
}
