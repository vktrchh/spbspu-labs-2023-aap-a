#include "square.hpp"

double Square::getArea() const
{
  return length_ * length_;
}

rectangle_t Square::getFrameRect() const
{
  point_t pos(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  return rectangle_t(length_, length_, pos);
}

void Square::move(double dx, double dy)
{
  point_t shift(dx, dy);
  downLeft_ += shift;
}

void Square::move(const point_t& p)
{
  point_t pos(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  double shiftX = p.getX() - pos.getX();
  double shiftY = p.getY() - pos.getY();
  move(shiftX,  shiftY);
}


void Square::scale(double k)
{
  point_t center(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  downLeft_ = center - (center - downLeft_) * k;
  length_ *= k;
}
