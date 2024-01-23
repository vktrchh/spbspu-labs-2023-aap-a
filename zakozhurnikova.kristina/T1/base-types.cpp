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

point_t zakozhurnikova::point_t::operator+(const point_t& p) const
{
  return point_t(x_ + p.x_, y_ + p.y_);
}

point_t zakozhurnikova::point_t::operator-(const point_t& p) const
{
  return point_t(x_ - p.x_, y_ - p.y_);
}

point_t zakozhurnikova::point_t::operator*(double k) const
{
  return point_t(x_ * k, y_ * k);
}

point_t zakozhurnikova::point_t::operator/(double k) const
{
  if (k == 0)
  {
    throw std::invalid_argument("Division by ZERO.");
  }
  return point_t(x_ / k, y_ / k);
}

point_t zakozhurnikova::point_t::scaleShift(double k, const point_t& p)
{
  double shiftX = p.x_ + k * (x_ - p.x_);
  double shiftY = p.y_ + k * (y_ - p.y_);
  return point_t(shiftX, shiftY);
}

point_t& zakozhurnikova::point_t::operator-()
{
  x_ *= -1;
  y_ *= -1;
  return *this;
}


void zakozhurnikova::rectangle_t::showCoordinates() const
{
  point_t downLeft(width_ - 2 * pos_.getX(),
    height_ - 2 * pos_.getY());
  point_t upRight(width_, height_);
  std::cout << downLeft.getX() << ' ' << downLeft.getY() <<
    ' ' << upRight.getX() << ' ' << upRight.getY() << '\n';
}

point_t zakozhurnikova::rectangle_t::getCenter() const
{
  return pos_;
}
