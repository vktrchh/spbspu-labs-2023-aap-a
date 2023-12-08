#include "Rectangle.hpp"

zhalilov::Rectangle::Rectangle(const point_t &leftAngle, const point_t &rightAngle)
{
  m_frameRect.width = rightAngle.x - leftAngle.x;
  m_frameRect.height = rightAngle.y - leftAngle.y;
  double posX = leftAngle.x + m_frameRect.width / 2;
  double posY = leftAngle.y + m_frameRect.height / 2;
  m_frameRect.pos = {posX, posY};
}

double zhalilov::Rectangle::getArea() const
{
  return m_frameRect.width * m_frameRect.height;
}

rectangle_t zhalilov::Rectangle::getFrameRect() const
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
  m_frameRect.width *= ratio;
}
