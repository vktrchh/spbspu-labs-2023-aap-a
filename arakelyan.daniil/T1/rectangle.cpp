#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t fp, point_t sp):
  pointRightUp_(fp),
  pointLeftDown_(sp),
  midpoint_{((pointRightUp_.x_ + pointLeftDown_.x_) / 2), ((pointRightUp_.y_ + pointLeftDown_.y_) / 2)}
{
  if (pointLeftDown_.y_ > pointRightUp_.y_ || pointLeftDown_.x_ > pointRightUp_.x_)
  {
    throw std::logic_error("Invalid arguments!");
  }
};

Rectangle::~Rectangle()
{};

double Rectangle::getArea() const
{
  double width = pointRightUp_.x_ - pointLeftDown_.x_;
  double height = pointRightUp_.y_ - pointLeftDown_.y_;
  return width * height;
}

rectangle_t Rectangle::getFrameRect()
{
  double width = std::abs(pointRightUp_.x_ - pointLeftDown_.x_);
  double height = std::abs(pointRightUp_.y_ - pointLeftDown_.y_);
  rectangle_t data = {width, height, midpoint_};
  return data;
};

void Rectangle::move(const double delX, const double delY)
{
  pointLeftDown_.x_ += delX;
  pointLeftDown_.y_ += delY;
  pointRightUp_.x_ += delX;
  pointRightUp_.y_ += delY;
  midpoint_.x_ += delX;
  midpoint_.y_ += delY;
}

void Rectangle::move(const point_t point)
{
  double dx = point.x_ - midpoint_.x_;
  double dy = point.y_ - midpoint_.y_;
  pointRightUp_.x_ += dx;
  pointRightUp_.y_ += dy;
  pointLeftDown_.x_ += dx;
  pointLeftDown_.y_ += dy;
  midpoint_ = point;
}

void Rectangle::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Rectangle)");
  }
  double width = std::abs(pointRightUp_.x_ - pointLeftDown_.x_);
  double height = std::abs(pointRightUp_.y_ - pointLeftDown_.y_);
  double widthWithScale = width * k;
  double heightWithScale = height * k;
  double widthHalf = widthWithScale / 2.0;
  double heightHalf = heightWithScale / 2.0;
  pointLeftDown_.x_ -= widthHalf;
  pointLeftDown_.y_ -= heightHalf;
  pointRightUp_.x_ += widthHalf;
  pointRightUp_.y_ += heightHalf;
}
