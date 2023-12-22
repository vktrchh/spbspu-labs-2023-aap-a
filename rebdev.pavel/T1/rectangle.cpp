#include "rectangle.hpp"

rebdev::Rectangle::Rectangle():
  lowLeftAngle_(point_t{0.0, 0.0}),
  upRightAngle_(point_t{0.0, 0.0})
{};
rebdev::Rectangle::Rectangle(const point_t & lowLeftAngle, const point_t & upRightAngle):
  lowLeftAngle_(lowLeftAngle),
  upRightAngle_(upRightAngle)
{};
rebdev::Rectangle::Rectangle(const double xLLA, const double yLLA, const double xURA, const double yURA):
  lowLeftAngle_(point_t{xLLA, yLLA}),
  upRightAngle_(point_t{xURA, yURA})
{};


double rebdev::Rectangle::getArea() const
{
  //some realization
  return  0.0;
};

rebdev::rectangle_t rebdev::Rectangle::getFrameRect()
{
  //some realization
  return rectangle_t{0.0, 0.0, 0.0};
};

void rebdev::Rectangle::move(const rectangle_t &)
{
  //some realization
};

void rebdev::Rectangle::move(const double x, const double y)
{
  lowLeftAngle_.x_ += x;
  lowLeftAngle_.y_ += y;
  //some realization
};

void rebdev::Rectangle::scale(const double k)
{
  lowLeftAngle_.x_ += k;
  //somerealization
};
