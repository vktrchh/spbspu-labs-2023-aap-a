#include "polygon.hpp"

#include <stdexcept>
#include <algorithm>

zhalilov::Polygon::Polygon(point_t *points, const size_t size)
{
  if (size < 3)
  {
    delete[] points;
    throw std::invalid_argument("not enough points to describe polygon");
  }
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if ((points[i].x == points[j].x)
        && (points[i].y == points[j].y))
      {
        delete[] points;
        throw std::invalid_argument("some points are equal");
      }
    }
  }
  point_t maxY = points[0], minY = points[0];
  point_t maxX = points[0], minX = points[0];
  for (size_t i = 1; i < size; i++)
  {
    if (points[i].x > maxX.x)
    {
      maxX = points[i];
    }
    if (points[i].x < minX.x)
    {
      minX = points[i];
    }
    if (points[i].y > maxY.y)
    {
      maxY = points[i];
    }
    if (points[i].y < minY.y)
    {
      minY = points[i];
    }
  }
  m_frameRect.width = maxX.x - minX.x;
  m_frameRect.height = maxY.y - minY.y;
  double width = m_frameRect.width;
  double height = m_frameRect.height;
  m_frameRect.pos = { minX.x + width / 2.0, minY.y + height / 2.0 };

  double deltaX = 0.0;
  double deltaY = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    deltaX += points[i].x;
    deltaY += points[i].y;
  }
  deltaX = deltaX / size;
  deltaY = deltaY / size;
  m_pos = { deltaX, deltaY };

  m_square = 0.0;
  for (size_t i = 0; i < size - 1; i++)
  {
    m_square -= points[i].x * points[i + 1].y;
  }
  m_square -= points[size - 1].x * points[0].y;
  for (size_t i = 0; i < size - 1; i++)
  {
    m_square += points[i].y * points[i + 1].x;
  }
  m_square += points[size - 1].y * points[0].x;
  m_square *= 0.5;
  delete[] points;
}

zhalilov::Polygon::~Polygon()
{
}

double zhalilov::Polygon::getArea() const
{
  return m_square;
}

zhalilov::rectangle_t zhalilov::Polygon::getFrameRect() const
{
  return m_frameRect;
}

void zhalilov::Polygon::move(const point_t &point)
{
  point_t deltaPos = { m_pos.x - m_frameRect.pos.x, m_pos.y - m_frameRect.pos.y };
  m_pos = point;
  m_frameRect.pos = { m_pos.x - deltaPos.x, m_pos.y - deltaPos.y };
}

void zhalilov::Polygon::move(const double dx, const double dy)
{
  m_pos.x += dx;
  m_pos.y += dy;
  m_frameRect.pos.x += dx;
  m_frameRect.pos.y += dy;
}

void zhalilov::Polygon::scale(const double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("ratio should be greater than zero");
  }
  m_frameRect.width *= ratio;
  m_frameRect.height *= ratio;
  double dx = (m_pos.x - m_frameRect.pos.x) * ratio;
  double dy = (m_pos.y - m_frameRect.pos.y) * ratio;
  m_frameRect.pos = { m_pos.x - dx, m_pos.y - dy };
  m_square *= (ratio * ratio);
}
