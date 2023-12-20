#include "polygon.hpp"

#include <stdexcept>
#include <algorithm>

zhalilov::Polygon::Polygon(const point_t *points, const size_t size):
  m_points(points),
  m_size(size),
  m_square(0.0),
  m_pos{ 0.0, 0.0 },
  m_frameRect{ 0.0, 0.0, { 0.0, 0.0 } }
{
  if (size < 3)
  {
    delete[] m_points;
    throw std::invalid_argument("not enough points to describe polygon");
  }
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if ((m_points[i].x == m_points[j].x)
        && (m_points[i].y == m_points[j].y))
      {
        delete[] m_points;
        throw std::invalid_argument("some points are equal");
      }
    }
  }
  point_t maxY = m_points[0], minY = m_points[0];
  point_t maxX = m_points[0], minX = m_points[0];
  for (size_t i = 1; i < size; i++)
  {
    if (m_points[i].x > maxX.x)
    {
      maxX = m_points[i];
    }
    if (m_points[i].x < minX.x)
    {
      minX = m_points[i];
    }
    if (m_points[i].y > maxY.y)
    {
      maxY = m_points[i];
    }
    if (m_points[i].y < minY.y)
    {
      minY = m_points[i];
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
    deltaX += m_points[i].x;
    deltaY += m_points[i].y;
  }
  deltaX = deltaX / size;
  deltaY = deltaY / size;
  m_pos = { deltaX, deltaY };

  m_square = 0.0;
  for (size_t i = 0; i < size - 1; i++)
  {
    m_square -= m_points[i].x * m_points[i + 1].y;
  }
  m_square -= m_points[size - 1].x * m_points[0].y;
  for (size_t i = 0; i < size - 1; i++)
  {
    m_square += m_points[i].y * m_points[i + 1].x;
  }
  m_square += m_points[size - 1].y * m_points[0].x;
  m_square *= 0.5;
}

zhalilov::Polygon::~Polygon()
{
  delete[] m_points;
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
