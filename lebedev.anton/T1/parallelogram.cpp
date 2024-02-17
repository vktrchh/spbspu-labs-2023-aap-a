#include "parallelogram.hpp"
#include <stdexcept>

lebedev::Parallelogram::Parallelogram(const point_t & p1, const point_t & p2, const point_t & p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  if (p1_.y != p2_.y && p2_.y != p3_.y)
  {
    throw std::invalid_argument("Error: invalid arguments for the Parallelogram");
  }
}
double lebedev::Parallelogram::getArea() const
{
  double a = 0;
  double h = 0;
  if (p1_.y == p2_.y)
  {
    a = std::abs(p1_.x - p2_.x);
    h = std::abs(p2_.y - p3_.y);
  }
  else
  {
    a = std::abs(p2_.x - p3_.x);
    h = std::abs(p1_.y - p2_.y);
  }
  return a * h;
}
lebedev::rectangle_t lebedev::Parallelogram::getFrameRect() const
{
  double width = 0;
  double height = 0;
  double center_x = 0;
  double center_y = (p1_.y + p3_.y) / 2;
  if (p1_.y == p2_.y)
  {
    height = std::abs(p2_.y - p3_.y);
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      width = std::abs(p1_.x - p3_.x);
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p1_.x - p2_.x) >= 0)
      {
        center_x = p2_.x + width / 2;
      }
      else
      {
        center_x = p2_.x - width / 2;
      }
    }
  }
  else
  {
    height = std::abs(p1_.y - p2_.y);
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      width = std::abs(p1_.x - p3_.x);
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p2_.x - p3_.x) >= 0)
      {
        center_x = p2_.x - width / 2;
      }
      else
      {
        center_x = p2_.x + width / 2;
      }
    }
  }
  point_t center = {center_x, center_y};
  return {width, height, center};
}
void lebedev::Parallelogram::move(const point_t & p)
{
  double center_x = 0;
  double center_y = center_y = (p1_.y + p3_.y) / 2;
  double width = 0;
  if (p1_.y == p2_.y)
  {
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p1_.x - p2_.x) >= 0)
      {
        center_x = p2_.x + width / 2;
      }
      else
      {
        center_x = p2_.x - width / 2;
      }
    }
  }
  else
  {
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p2_.x - p3_.x) >= 0)
      {
        center_x = p2_.x - width / 2;
      }
      else
      {
        center_x = p2_.x + width / 2;
      }
    }
  }
  double dx = p.x - center_x;
  double dy = p.y - center_y;
  move(dx, dy);
}
void lebedev::Parallelogram::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}
void lebedev::Parallelogram::scale(double ratio)
{
  if (ratio <= 0)
  {
    throw std::invalid_argument("Error: invalid argument for the Scale");
  }
  double center_x = 0;
  double center_y = center_y = (p1_.y + p3_.y) / 2;
  double width = 0;
  if (p1_.y == p2_.y)
  {
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p1_.x - p2_.x) >= 0)
      {
        center_x = p2_.x + width / 2;
      }
      else
      {
        center_x = p2_.x - width / 2;
      }
    }
  }
  else
  {
    if (p1_.x <= p2_.x && p2_.x <= p3_.x)
    {
      center_x = (p1_.x + p3_.x) / 2;
    }
    else
    {
      width = std::abs(p2_.x - p3_.x) + std::abs(p1_.x - p2_.x);
      if ((p2_.x - p3_.x) >= 0)
      {
        center_x = p2_.x - width / 2;
      }
      else
      {
        center_x = p2_.x + width / 2;
      }
    }
  }
  point_t center = {center_x, center_y};
  p1_ = scalePoint(p1_, center, ratio);
  p2_ = scalePoint(p2_, center, ratio);
  p3_ = scalePoint(p3_, center, ratio);
}
