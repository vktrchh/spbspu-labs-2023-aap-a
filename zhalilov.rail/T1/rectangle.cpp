#include "rectangle.hpp"

#include <stdexcept>

zhalilov::Rectangle::Rectangle(double width, double height, const point_t &center):
  m_frameRect{ width, height, center }
{
  if (m_frameRect.width <= 0.0
    || m_frameRect.height <= 0.0)
  {
    throw std::invalid_argument("invalid rectangle source");
  }
}

zhalilov::Rectangle::~Rectangle()
{
}

double zhalilov::Rectangle::getArea() const
{
  return m_frameRect.width * m_frameRect.height;
}

zhalilov::rectangle_t zhalilov::Rectangle::getFrameRect() const
{
  return m_frameRect;
}

void zhalilov::Rectangle::move(const point_t &point)
{
  m_frameRect.pos = point;
}

void zhalilov::Rectangle::move(const double dx, const double dy)
{
  m_frameRect.pos = {m_frameRect.pos.x + dx, m_frameRect.pos.y + dy};
}

void zhalilov::Rectangle::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("scaling ratio should be more than zero");
  }
  m_frameRect.width *= ratio;
  m_frameRect.height *= ratio;
}
