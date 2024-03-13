#include "rectangle.hpp"
#include <stdexcept>

agarkov::Rectangle::Rectangle(agarkov::point_t left_bottom, agarkov::point_t right_top):
  left_bottom_(left_bottom),
  right_top_(right_top)
{
  if (!isCorrectRectangle())
  {
    throw std::invalid_argument("Incorrect rectangle argument");
  }
}

double agarkov::Rectangle::getArea() const
{
  return getFrameRectangle().height_ * getFrameRectangle().width_;
}

agarkov::rectangle_t agarkov::Rectangle::getFrameRectangle() const
{
  point_t centre_frame_rect = getLineCenter(left_bottom_, right_top_);
  double height_frame_rect = right_top_.y_ - left_bottom_.y_;
  double width_frame_rect = right_top_.x_ - left_bottom_.x_;
  return {centre_frame_rect, width_frame_rect, height_frame_rect};
}

void agarkov::Rectangle::move(const double dx, const double dy)
{
  left_bottom_.move(dx, dy);
  right_top_.move(dx, dy);
}

void agarkov::Rectangle::move(const agarkov::point_t position)
{
  point_t centre = getLineCenter(left_bottom_, right_top_);
  double dx = position.x_ - centre.x_;
  double dy = position.y_ - centre.y_;
  move(dx, dy);
}

void agarkov::Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point_t center = getFrameRectangle().pos_;
  left_bottom_.x_ = center.x_ + (left_bottom_.x_ - center.x_) * k;
  left_bottom_.y_ = center.y_ + (left_bottom_.y_ - center.y_) * k;
  right_top_.x_ = center.x_ + (right_top_.x_ - center.x_) * k;
  right_top_.y_ = center.y_ + (right_top_.y_ - center.y_) * k;
}

bool agarkov::Rectangle::isCorrectRectangle() const
{
  return ((left_bottom_.x_ < right_top_.x_) && (left_bottom_.y_ < right_top_.y_));
}
