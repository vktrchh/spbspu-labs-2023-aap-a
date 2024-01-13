#include "rectangle.hpp"

rebdev::Rectangle::Rectangle():
  angles_(nullptr)
{};
rebdev::Rectangle::Rectangle(point_t * angles):
  angles_(angles)
{}

rebdev::Rectangle::~Rectangle()
{
  delete[] angles_;
};

double rebdev::Rectangle::getArea() const
{
  return  ((angles_[1].x_ - angles_[0].x_) * (angles_[1].y_ - angles_[0].y_));
};

rebdev::rectangle_t rebdev::Rectangle::getFrameRect() const
{
  double width = angles_[1].x_ - angles_[0].x_;
  double height = angles_[1].y_ - angles_[0].y_;
  point_t pos = {(angles_[1].x_ + angles_[0].x_)/2, (angles_[1].y_ + angles_[0].y_)/2};
  return rectangle_t{width, height, pos};
};

void rebdev::Rectangle::move(const point_t point)
{
  rectangle_t frameRectangle = getFrameRect();

  double yChange = frameRectangle.pos_.y_ - point.y_;
  double xChange = frameRectangle.pos_.x_ - point.x_;

  angles_[1].y_ += yChange;
  angles_[1].x_ += xChange;
  angles_[0].y_ += yChange;
  angles_[0].x_ += xChange;
};

void rebdev::Rectangle::move(const double x, const double y)
{
  angles_[0].x_ += x;
  angles_[0].y_ += y;
  angles_[1].x_ += x;
  angles_[1].y_ += y;
};

void rebdev::Rectangle::scale(const double k)
{
  rectangle_t frameRectangle = getFrameRect();

  angles_[1].x_ = (angles_[1].x_ - frameRectangle.pos_.x_) * k + frameRectangle.pos_.x_;
  angles_[1].y_ = (angles_[1].y_ - frameRectangle.pos_.y_) * k + frameRectangle.pos_.y_;
  angles_[0].x_ = (angles_[0].x_ - frameRectangle.pos_.x_) * k + frameRectangle.pos_.x_;
  angles_[0].y_ = (angles_[0].y_ - frameRectangle.pos_.y_) * k + frameRectangle.pos_.y_;
};
