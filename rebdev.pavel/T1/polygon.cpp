#include "polygon.hpp"
#include <cstddef>
#include <limits>
#include <iostream>

rebdev::Polygon::Polygon(const point_t * vertexs, const size_t numOfVertexs):
  vertexs_(nullptr),
  numOfVertexs_(numOfVertexs)
{
  try
  {
    vertexs_ = new point_t[numOfVertexs_];
  }
  catch (const std::exception & e)
  {
    delete[] vertexs_;
    throw;
  }

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i] = vertexs[i];
  }
};

rebdev::Polygon::~Polygon()
{
  delete[] vertexs_;
};

double rebdev::Polygon::getArea() const
{
  double sum = 0;
  for(size_t i = 0; i < (numOfVertexs_ - 1); ++i)
  {
    sum += (vertexs_[i].x - vertexs_[i + 1].x) * (vertexs_[i].y + vertexs_[i + 1].y);
  }
  sum += (vertexs_[numOfVertexs_ - 1].x - vertexs_[0].x) * (vertexs_[numOfVertexs_ - 1].y + vertexs_[0].y);
  sum /= 2;
  return  ((sum >= 0) ? sum : -sum);
};

rebdev::rectangle_t rebdev::Polygon::getFrameRect() const
{
  double xMin = std::numeric_limits< double >::max(), xMax = std::numeric_limits< double >::min();
  double yMin = xMin, yMax = xMax;
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    xMin = ((xMin >= vertexs_[i].x) ? vertexs_[i].x : xMin);
    yMin = ((yMin >= vertexs_[i].y) ? vertexs_[i].y : yMin);
    xMax = ((xMax <= vertexs_[i].x) ? vertexs_[i].x : xMax);
    yMax = ((yMax <= vertexs_[i].y) ? vertexs_[i].y : yMax);
  }
  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{xMin + (xMax - xMin)/2, yMin + (yMax - yMin)/2}};
};

void rebdev::Polygon::move(const point_t point)
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    center.x += vertexs_[i].x;
    center.y += vertexs_[i].y;
  }

  center.x /= numOfVertexs_;
  center.y /= numOfVertexs_;

  double xChange = center.x - point.x;
  double yChange = center.y - point.y;
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x += xChange;
    vertexs_[i].y += yChange;
  }
};

void rebdev::Polygon::move(const double x, const double y)
{
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x += x;
    vertexs_[i].y += y;
  }
};

void rebdev::Polygon::scale(const double k)
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    center.x += vertexs_[i].x;
    center.y += vertexs_[i].y;
  }

  center.x /= numOfVertexs_;
  center.y /= numOfVertexs_;

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x = (vertexs_[i].x - center.x) * k + center.x;
    vertexs_[i].y = (vertexs_[i].y - center.y) * k + center.y;
  }

};
