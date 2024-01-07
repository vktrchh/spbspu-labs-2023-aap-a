#include "rectangle.hpp"

chistyakov::Rectangle::Rectangle(const point_t & leftCorner, const point_t rightCorner):
  leftCorner_(leftCorner),
  rightCorner_(rightCorner)
{
  if (leftCorner.x >= rightCorner.x || leftCorner.y >= rightCorner.y)
  {
    throw std::invalid_argument("Invalid argument for rectangle");
  }
}

chistyakov::Rectangle::~Rectangle()
{
}

double chistyakov::Rectangle::getArea() const
{
  rectangle_t area = getFrameRect();
  return area.width * area.height;
}

rectangle_t chistyakov::Rectangle::getFrameRect() const
{
  double width = rightCorner_.x - leftCorner_.x;
  double height = rightCorner_.y - leftCorner_.y;
  point_t pos = { width/2.0 + leftCorner_.x, height/2.0 + leftCorner_.y};
  return {width, height, pos};
}

void chistyakov::Rectangle::move(const point_t & point)
{
  leftCorner_.x += point.x;
  leftCorner_.y += point.y;
  rightCorner_.x += point.x;
  rightCorner_.y += point.y;
}

void chistyakov::Rectangle::move(const double mx, const double my)
{
  leftCorner_.x += mx;
  leftCorner_.y += my;
  rightCorner_.x += mx;
  rightCorner_.y += my;
}

void scale(const double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Invalid argument for ratio");
  }

  rectangle_t area = getFrameRect();
  leftCorner_.x -= (area.width * ratio - area.width) / 2.0;
  leftCorner_.y -= (area.height * ratio - area.height) / 2.0;
  rightCorner_.x += (area.width * ratio - area.width) / 2.0;
  rightCorner_.y += (area.height * ratio - area.height) / 2.0;
}
