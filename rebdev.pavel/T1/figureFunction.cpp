#include "figureFunction.hpp"
#include <algorithm>
#include <stdexcept>

rebdev::rectangle_t rebdev::getFrameRectangle(const point_t vertexes[], size_t numOfVertexes)
{
  double xMin = vertexes[0].x, xMax = vertexes[0].x;
  double yMin = vertexes[0].y, yMax = vertexes[0].y;
  for (size_t i = 0; i < numOfVertexes; ++i)
  {
    xMin = std::min(xMin, vertexes[i].x);
    yMin = std::min(yMin, vertexes[i].y);
    xMax = std::max(xMax, vertexes[i].x);
    yMax = std::max(yMax, vertexes[i].y);
  }

  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{(xMax + xMin) / 2, (yMax + yMin) / 2}};
}

void rebdev::scaleFigure(point_t vertexes[], size_t numOfVertexes, const point_t & center, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Bad koeff");
  }

  for (size_t i = 0; i < numOfVertexes; ++i)
  {
    vertexes[i].x = (vertexes[i].x - center.x) * k + center.x;
    vertexes[i].y = (vertexes[i].y - center.y) * k + center.y;
  }
}
