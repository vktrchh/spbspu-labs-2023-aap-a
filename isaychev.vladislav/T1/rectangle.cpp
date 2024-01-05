#include "rectangle.hpp"

isaychev::Rectangle::Rectangle(const point_t & p1, const point_t & p2):
  botL_(p1),
//  botL_.y_(p1.y_),
  topR_(p2)
//  topR_.y_(p2.y_)
{}

double isaychev::Rectangle::getArea() const
{
  return 2.0;
}

isaychev::rectangle_t isaychev::Rectangle::getFrameRect() const
{
  isaychev::rectangle_t rec = {0, 0, {0, 0}};
  return rec;
}

void isaychev::Rectangle::move(point_t & newPos)
{}

void isaychev::Rectangle::move(double dX, double dY)
{}

void isaychev::Rectangle::scale(double x, double y, double coeff)
{}
