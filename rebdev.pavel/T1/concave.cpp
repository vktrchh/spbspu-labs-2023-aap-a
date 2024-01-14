#include "concave.hpp"
#include <limits>

rebdev::Concave::Concave():
  vertexs_{nullptr}
{};
rebdev::Concave::Concave(point_t * vertexs):
  vertexs_{vertexs}
{};

rebdev::Concave::~Concave()
{
  delete[] vertexs_;
};

double rebdev::Concave::getArea() const
{
  double sum  = 0;
  for(int i = 0; i < 4; ++i)
  {
    sum += (vertexs_[i].x * vertexs_[(i + 1) % 4].y) - (vertexs_[(i + 1) % 4].x * vertexs_[i].y);
  }
  sum /= 2;

  return ((sum < 0) ? -sum : sum);
};

rebdev::rectangle_t rebdev::Concave::getFrameRect() const
{
  double xMin = std::numeric_limits< double >::max(), xMax = std::numeric_limits< double >::min();
  double yMin = xMin, yMax = xMax;
  for (int i = 0; i < 4; ++i)
  {
    xMin = ((xMin >= vertexs_[i].x) ? vertexs_[i].x : xMin);
    yMin = ((yMin >= vertexs_[i].y) ? vertexs_[i].y : yMin);
    xMax = ((xMax <= vertexs_[i].x) ? vertexs_[i].x : xMax);
    yMax = ((yMax <= vertexs_[i].y) ? vertexs_[i].y : yMax);
  }
  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{xMin + (xMax - xMin)/2, yMin + (yMax - yMin)/2}};
};

void rebdev::Concave::move(const point_t point)
{
  double yChange = vertexs_[3].y - point.y;
  double xChange = vertexs_[3].x - point.x;
  for (int i = 0; i < 4; ++i)
  {
    vertexs_[i].x += xChange;
    vertexs_[i].y += yChange;
  }
};

void rebdev::Concave::move(const double x, const double y)
{
  for (int i = 0; i < 4; ++i)
  {
    vertexs_[i].x += x;
    vertexs_[i].y += y;
  }
};

void rebdev::Concave::scale(const double k)
{
  for (int i = 0; i < 3; ++i)
  {
    vertexs_[i].x = (vertexs_[i].x - vertexs_[3].x) * k + vertexs_[3].x;
    vertexs_[i].y = (vertexs_[i].y - vertexs_[3].y) * k + vertexs_[3].y;
  }
};
