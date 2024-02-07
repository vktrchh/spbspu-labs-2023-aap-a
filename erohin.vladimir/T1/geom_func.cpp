#include "geom_func.hpp"
#include <cmath>
#include <stdexcept>

void erohin::isoScale(Shape* shape, const point_t& pos, double ratio)
{
  point_t init_pos = shape->getFrameRect().pos;
  shape->move(pos);
  point_t new_pos = shape->getFrameRect().pos;
  shape->scale(ratio);
  shape->move(ratio * (init_pos.x - new_pos.x), ratio * (init_pos.y - new_pos.y));
}

double erohin::getDistance(const point_t& from, const point_t& to)
{
  double dx = from.x - to.x;
  double dy = from.y - to.y;
  return std::sqrt(dx * dx + dy * dy);
}

double* erohin::getSides(const point_t* point, unsigned int side_number)
{
  double* side = new double[side_number] { 0.0 };
  for (unsigned int i = 0; i < side_number; ++i)
  {
    side[i] = getDistance(point[i], point[(i + 1) % side_number]);
  }
  return side;
}

bool erohin::isPointOnSegment(const point_t& point, const point_t& begin, const point_t& end)
{
  return ((point.x - begin.x) * (point.x - end.x) < 0.0 && (point.y - begin.y) * (point.y - end.y) < 0.0);
}

erohin::point_t erohin::findIntersectionPoint(const point_t* point)
{
  double dx[3]{ 0.0 };
  double dy[3]{ 0.0 };
  for (int i = 0; i < 3; ++i)
  {
    dx[i] = point[i + 1].x - point[i].x;
    dy[i] = point[i + 1].y - point[i].y;
  }
  if (dy[0] * dx[2] == dy[2] * dx[0] || dx[0] == 0.0)
  {
    throw std::invalid_argument("Cannot find intersection");
  }
  erohin::point_t result = {0.0, 0.0};
  result.x = (point[2].y * dx[2] - point[2].x * dy[2]) * dx[0];
  result.x -= (point[0].y * dx[0] - point[0].x * dy[0]) * dx[0];
  result.x /= (dy[0] * dx[2] - dy[2] * dx[0]);
  result.y = point[0].y + (dy[0] / dx[0]) * (result.x - point[0].x);
  return result;
}
