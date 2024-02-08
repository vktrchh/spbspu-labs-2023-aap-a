#include "rectangle.hpp"
#include <stdexcept>

double zakozhurnikova::Rectangle::getArea() const
{
  double width = upRight_.getX() - downLeft_.getX();
  double height = upRight_.getY() - downLeft_.getY();
  return width * height;
}

zakozhurnikova::rectangle_t zakozhurnikova::Rectangle::getFrameRect() const
{
  double width = upRight_.getX() - downLeft_.getX();
  double height = upRight_.getY() - downLeft_.getY();
  point_t pos((upRight_ + downLeft_) / 2.0);
  return zakozhurnikova::rectangle_t(width, height, pos);
}

void zakozhurnikova::Rectangle::move(const point_t& p)
{
  zakozhurnikova::point_t center((downLeft_ + upRight_)  / 2.0);
  double shiftX = p.getX() - center.getX();
  double shiftY = p.getY() - center.getY();
  move(shiftX, shiftY);
}

void zakozhurnikova::Rectangle::move(double dx, double dy)
{
 zakozhurnikova::point_t shift(dx, dy);
  downLeft_ += shift;
  upRight_ += shift;
}

void zakozhurnikova::Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Scale coefficient should be a positive real number.");
  }
  zakozhurnikova::point_t pos((downLeft_ + upRight_) / 2.0);
  downLeft_ = downLeft_.scaleShift(k, pos);
  upRight_ = upRight_.scaleShift(k, pos);
}
