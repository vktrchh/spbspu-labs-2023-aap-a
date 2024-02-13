#include "polygon.hpp"
#include "figureFunction.hpp"

#include <iostream>

rebdev::Polygon::Polygon(const point_t * vertexs, size_t numOfVertexs):
  vertexs_(nullptr),
  numOfVertexs_(numOfVertexs)
{
  if (numOfVertexs < 3)
  {
    throw std::logic_error("polygon error");
  }
  for (size_t i = 0; i < (numOfVertexs - 1); ++i)
  {
    for (size_t j = (i + 1); j < numOfVertexs; ++j)
    {
      if ((vertexs[i].x == vertexs[j].x) && (vertexs[i].y == vertexs[j].y))
      {
        throw std::logic_error("polygon error");
      }
    }
  }

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
}

rebdev::Polygon::~Polygon()
{
  delete[] vertexs_;
}

double rebdev::Polygon::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < (numOfVertexs_ - 1); ++i)
  {
    sum += (vertexs_[i].x - vertexs_[i + 1].x) * (vertexs_[i].y + vertexs_[i + 1].y);
  }
  sum += (vertexs_[numOfVertexs_ - 1].x - vertexs_[0].x) * (vertexs_[numOfVertexs_ - 1].y + vertexs_[0].y);
  sum /= 2;
  return  ((sum >= 0) ? sum : -sum);
}

rebdev::rectangle_t rebdev::Polygon::getFrameRect() const
{
  return getFrameRectangle(vertexs_, numOfVertexs_);
}

void rebdev::Polygon::move(const point_t & point)
{
  point_t center = getPolygonCenter();

  double xChange = point.x - center.x;
  double yChange = point.y - center.y;
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x += xChange;
    vertexs_[i].y += yChange;
  }
}

void rebdev::Polygon::move(double x, double y)
{
  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x += x;
    vertexs_[i].y += y;
  }
}

void rebdev::Polygon::scale(double k)
{
  point_t center = getPolygonCenter();

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    vertexs_[i].x = (vertexs_[i].x - center.x) * k + center.x;
    vertexs_[i].y = (vertexs_[i].y - center.y) * k + center.y;
  }

}

rebdev::point_t rebdev::Polygon::getPolygonCenter()
{
  point_t center{0.0, 0.0};

  for (size_t i = 0; i < numOfVertexs_; ++i)
  {
    center.x += vertexs_[i].x;
    center.y += vertexs_[i].y;
  }

  center.x /= numOfVertexs_;
  center.y /= numOfVertexs_;

  return center;
}
