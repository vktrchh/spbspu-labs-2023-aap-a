#include "square.hpp"

double zakozhurnikova::Square::getArea() const
{
  return length_ * length_;
}

zakozhurnikova::rectangle_t zakozhurnikova::Square::getFrameRect() const
{
  zakozhurnikova::point_t pos(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  return zakozhurnikova::rectangle_t(length_, length_, pos);
}

void zakozhurnikova::Square::move(double dx, double dy)
{
  zakozhurnikova::point_t shift(dx, dy);
  downLeft_ += shift;
}

void zakozhurnikova::Square::move(const point_t& p)
{
  zakozhurnikova::point_t pos(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  double shiftX = p.getX() - pos.getX();
  double shiftY = p.getY() - pos.getY();
  move(shiftX,  shiftY);
}


void zakozhurnikova::Square::scale(double k)
{
  zakozhurnikova::point_t center(downLeft_.getX() + (length_ / 2.0), downLeft_.getY() + (length_ / 2.0));
  downLeft_ = center - (center - downLeft_) * k;
  length_ *= k;
}
