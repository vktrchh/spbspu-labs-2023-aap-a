#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(point_t p1, point_t p2):
  p1_(p1),
  p2_(p2)
{}
double Rectangle::getArea()
{
  return std::abs((p1_.x - p2_.x) * (p1_.y - p2_.y));
}
rectangle_t Rectangle::getFrameRect()
{
  return {std::abs(p1_.x - p2_.x), std::abs(p1_.y - p2_.y), pos_};
}
void Rectangle::move(point_t bias)
{
  this->move(bias.x - pos_.x, bias.y - pos_.y);
}
void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
}
void Rectangle::scale(double k)
{
  p1_.x = k * (pos_.x - p1_.x);
  p2_.x = k * (pos_.x - p2_.x);
  p1_.y = k * (pos_.y - p1_.y);
  p2_.y = k * (pos_.y - p2_.y);
}
