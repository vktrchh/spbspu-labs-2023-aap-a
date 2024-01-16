#include "rectangle.hpp"
#include <cmath>
#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

strelyaev::Rectangle::Rectangle(point_t p1, point_t p2):
  p1_(p1),
  p2_(p2),
  center_({(p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2})
{
  if (p1_.x >= p2_.x || p1_.y >= p2_.y)
  {
    throw std::invalid_argument("Invalid points for RECTANGLE");
  }
}

double strelyaev::Rectangle::getArea() const
{
  double height = std::abs(p1_.y - p2_.y);
  double width = std::abs(p1_.x - p2_.x);
  return height * width;
}

strelyaev::rectangle_t strelyaev::Rectangle::getFrameRect() const
{
  double height = std::abs(p1_.y - p2_.y);
  double width = std::abs(p1_.x - p2_.x);
  rectangle_t r1 = {width, height, center_};
  return r1;
}

void strelyaev::Rectangle::move(point_t new_center)
{
  double offset_x = new_center.x - center_.x;
  double offset_y = new_center.y - center_.y;
  p1_.x += offset_x;
  p1_.y += offset_y;
  p2_.x += offset_x;
  p2_.y += offset_y;
  center_ = new_center;
}

void strelyaev::Rectangle::move(double k)
{
  center_.x += k;
  center_.y += k;
  p1_.x += k;
  p1_.y += k;
  p2_.x += k;
  p2_.y += k;
}

void strelyaev::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
}

void strelyaev::Rectangle::scale(double k)
{
  double width = std::abs(p1_.x - p2_.x);
  double height = std::abs(p1_.y - p2_.y);

  double new_width = width * k;
  double new_height = height * k;

  double offset_x = (new_width - width) / 2.0;
  double offset_y = (new_height - height) / 2.0;
  p1_.x -= offset_x;
  p1_.y -= offset_y;
  p2_.x += offset_x;
  p2_.y += offset_y;
}
