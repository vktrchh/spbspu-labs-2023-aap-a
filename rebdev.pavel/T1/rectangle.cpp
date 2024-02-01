#include "rectangle.hpp"
#include <iostream>

rebdev::Rectangle::Rectangle(const point_t * angles):
  angles_(nullptr)
{
  if ((angles[0].x >= angles[1].x) || (angles[0].y >= angles[1].y))
  {
    throw std::logic_error("rectangle error");
  }
  try
  {
    angles_ = new point_t[2];
  }
  catch (const std::exception & e)
  {
    delete[] angles_;
    throw;
  }

  for (size_t i = 0; i < 2; ++i)
  {
    angles_[i] = angles[i];
  }
}

rebdev::Rectangle::~Rectangle()
{
  delete[] angles_;
};

double rebdev::Rectangle::getArea() const
{
  return  ((angles_[1].x - angles_[0].x) * (angles_[1].y - angles_[0].y));
};

rebdev::rectangle_t rebdev::Rectangle::getFrameRect() const
{
  double width = angles_[1].x - angles_[0].x;
  double height = angles_[1].y - angles_[0].y;
  point_t pos = {(angles_[1].x + angles_[0].x)/2, (angles_[1].y + angles_[0].y)/2};
  return rectangle_t{width, height, pos};
};

void rebdev::Rectangle::move(const point_t point)
{
  rectangle_t frameRectangle = getFrameRect();

  double yChange = frameRectangle.pos.y - point.y;
  double xChange = frameRectangle.pos.x - point.x;

  angles_[1].y += yChange;
  angles_[1].x += xChange;
  angles_[0].y += yChange;
  angles_[0].x += xChange;
};

void rebdev::Rectangle::move(const double x, const double y)
{
  angles_[0].x += x;
  angles_[0].y += y;
  angles_[1].x += x;
  angles_[1].y += y;
};

void rebdev::Rectangle::scale(const double k)
{
  rectangle_t frameRectangle = getFrameRect();

  angles_[1].x = (angles_[1].x - frameRectangle.pos.x) * k + frameRectangle.pos.x;
  angles_[1].y = (angles_[1].y - frameRectangle.pos.y) * k + frameRectangle.pos.y;
  angles_[0].x = (angles_[0].x - frameRectangle.pos.x) * k + frameRectangle.pos.x;
  angles_[0].y = (angles_[0].y - frameRectangle.pos.y) * k + frameRectangle.pos.y;
};
