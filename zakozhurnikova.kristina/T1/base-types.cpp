#include "base-types.hpp"
#include <cmath>
#include <iostream>

double zakozhurnikova::point_t::getDistance(const point_t& p) const
{
  double distance = std::sqrt((x - p.x) * (x - p.x) +
    (y - p.y) * (y - p.y));
  return distance;
}
void zakozhurnikova::point_t::operator+=(const point_t& p)
{
  x += p.x;
  y += p.y;
}

void zakozhurnikova::point_t::operator-=(const point_t& p)
{
  x -= p.x;
  y -= p.y;
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator+(const point_t& p) const
{
  return point_t{x + p.x, y + p.y};
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator-(const point_t& p) const
{
  return point_t{x - p.x, y - p.y};
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator*(double k) const
{
  return point_t{x * k, y * k};
}

zakozhurnikova::point_t zakozhurnikova::point_t::operator/(double k) const
{
  if (k == 0)
  {
    throw std::invalid_argument("Division by ZERO.");
  }
  point_t res = {x / k, y / k};
  return res;
}

zakozhurnikova::point_t& zakozhurnikova::point_t::operator-()
{
    x *= -1;
    y *= -1;
    return *this;
}

bool zakozhurnikova::point_t::operator==(const point_t& p) const
{
  return x == p.x && y == p.y;
}

zakozhurnikova::point_t zakozhurnikova::point_t::scaleShift(double k, const point_t& p) const
{
  double shiftX = p.x + k * (x - p.x);
  double shiftY = p.y + k * (y - p.y);
  return point_t{shiftX, shiftY};
}

void zakozhurnikova::rectangle_t::showCoordinates(std::ostream& out) const
{
  point_t downLeft = {pos.x - width / 2.0, pos.y - height / 2.0};
  point_t upRight = {pos.x + width / 2.0, pos.y + height / 2.0};
  out << downLeft.x << ' ' << downLeft.y << ' ' << upRight.x << ' ' << upRight.y;
}
