#include "base-types.hpp"
#include <cmath>
#include <iostream>

double zakozhurnikova::point_t::getDistance(const point_t& p) const
{
  double distance = std::sqrt((x_ - p.x_) * (x_ - p.x_) +
    (y_ - p.y_) * (y_ - p.y_));
  return distance;
}
void zakozhurnikova::point_t::operator+=(const point_t& p)
{
  x_ += p.x_;
  y_ += p.y_;
}

void zakozhurnikova::point_t::operator-=(const point_t& p)
{
  x_ -= p.x_;
  y_ -= p.y_;
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator+(const point_t& p) const
{
  return point_t(x_ + p.x_, y_ + p.y_);
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator-(const point_t& p) const
{
  return point_t(x_ - p.x_, y_ - p.y_);
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator*(double k) const
{
  return point_t(x_ * k, y_ * k);
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator/(double k) const
{
  if (k == 0)
  {
    throw std::invalid_argument("Division by ZERO.");
  }
  return zakozhurnikova::point_t(x_ / k, y_ / k);
}

zakozhurnikova::point_t& zakozhurnikova::point_t::operator-()
{
    x_ *= -1;
    y_ *= -1;
    return *this;
}

zakozhurnikova::point_t& zakozhurnikova::point_t::operator=(const point_t& point)
{
  this->x_ = point.x_;
  this->y_ = point.y_;
  return *this;
}

zakozhurnikova::point_t& zakozhurnikova::point_t::operator=(point_t&& point)
{
  this->x_ = point.x_;
  this->y_ = point.y_;
  point.x_ = 0.0;
  point.y_ = 0.0;
  return *this;
}

zakozhurnikova::point_t zakozhurnikova::point_t::scaleShift(double k, const point_t& p)
{
  double shiftX = p.x_ + k * (x_ - p.x_);
  double shiftY = p.y_ + k * (y_ - p.y_);
  return zakozhurnikova::point_t(shiftX, shiftY);
}

void zakozhurnikova::rectangle_t::showCoordinates() const
{
  zakozhurnikova::point_t downLeft(width_ - 2 * pos_.getX(),
    height_ - 2 * pos_.getY());
  zakozhurnikova::point_t upRight(width_, height_);
  std::cout << downLeft.getX() << ' ' << downLeft.getY() <<
    ' ' << upRight.getX() << ' ' << upRight.getY() << '\n';
}

zakozhurnikova::point_t zakozhurnikova::rectangle_t::getCenter() const
{
  return pos_;
}
