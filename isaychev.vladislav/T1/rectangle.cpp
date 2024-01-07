#include "rectangle.hpp"

isaychev::Rectangle::Rectangle(const point_t & p1, const point_t & p2):
  botL_(p1),
  topR_(p2)
{}

double isaychev::Rectangle::getArea() const
{
  return (topR_.x_ - botL_.x_) * (topR_.y_ - botL_.y_);
}

isaychev::rectangle_t isaychev::Rectangle::getFrameRect() const
{
  isaychev::rectangle_t rec = {0, 0, {0, 0}};
  rec.width = topR_.x_ - botL_.x_;
  rec.height = topR_.y_ - botL_.y_;
  rec.pos = {(topR_.x_ - botL_.x_) / 2, (topR_.y_ - botL_.y_) / 2};
  return rec;
}

void isaychev::Rectangle::move(const point_t & newPos)
{
  double width = topR_.x_ - botL_.x_;
  double height = topR_.y_ - botL_.y_;
  topR_ = {newPos.x_ + (width / 2), newPos.y_ + (height / 2)};
  botL_ = {newPos.x_ - (width / 2), newPos.y_ - (height / 2)};
}

void isaychev::Rectangle::move(const double dX, const double dY)
{
  topR_.x_ += dX;
  botL_.x_ += dX;
  topR_.y_ += dY;
  botL_.y_ += dY;
}

void isaychev::Rectangle::scale(const double coeff)
{
  double width05 = (topR_.x_ - botL_.x_) / 2;
  double height05 = (topR_.y_ - botL_.y_)  / 2;
  topR_.x_ += (coeff - 1.0) * width05;
  topR_.y_ += (coeff - 1.0) * height05;
  botL_.x_ -= (coeff - 1.0) * width05;
  botL_.y_ -= (coeff - 1.0) * height05;
}
