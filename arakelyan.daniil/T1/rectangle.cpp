#include <stdexcept>
#include "rectangle.hpp"
#include "base-types.hpp"

arakelyan::Rectangle::Rectangle(point_t fp, point_t sp):
  pointRightUp_(sp),
  pointLeftDown_(fp),
  midpoint_{((pointRightUp_.x + pointLeftDown_.x) / 2), ((pointRightUp_.y + pointLeftDown_.y) / 2)}
{
  if (pointLeftDown_.y > pointRightUp_.y || pointLeftDown_.x > pointRightUp_.x)
  {
    throw std::logic_error("Invalid arguments!");
  }
}

double arakelyan::Rectangle::getArea() const
{
  double width = pointRightUp_.x - pointLeftDown_.x;
  double height = pointRightUp_.y - pointLeftDown_.y;
  return width * height;
}

arakelyan::rectangle_t arakelyan::Rectangle::getFrameRect() const
{
  double width = std::abs(pointRightUp_.x - pointLeftDown_.x);
  double height = std::abs(pointRightUp_.y - pointLeftDown_.y);
  rectangle_t data = {width, height, midpoint_};
  return data;
}

void arakelyan::Rectangle::move(const double delX, const double delY)
{
  point_t * pointsArray[2] = {&pointLeftDown_, &pointRightUp_};
  for (size_t i = 0; i < 2; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
  midpoint_.x += delX;
  midpoint_.y += delY;
}

void arakelyan::Rectangle::move(const point_t point)
{
  double delX = point.x - midpoint_.x;
  double delY = point.y - midpoint_.y;
  move(delX, delY);
  midpoint_ = point;
}

void arakelyan::Rectangle::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Rectangle)");
  }
  rectangle_t data = getFrameRect();
  double widthWithScale = data.width * k;
  double heightWithScale = data.height * k;
  double widthHalf = widthWithScale / 2.0;
  double heightHalf = heightWithScale / 2.0;
  pointLeftDown_.x = data.pos.x - widthHalf;
  pointLeftDown_.y = data.pos.y - heightHalf;
  pointRightUp_.x = data.pos.x + widthHalf;
  pointRightUp_.y = data.pos.y + heightHalf;
}

arakelyan::Rectangle::~Rectangle()
{}
