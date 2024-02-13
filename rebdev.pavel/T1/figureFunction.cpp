#include "figureFunction.hpp"

rebdev::rectangle_t rebdev::getFrameRectangle(const point_t vertexs[], size_t numOfVertexs)
{
  double xMin = vertexs[0].x, xMax = vertexs[0].x;
  double yMin = vertexs[0].y, yMax = vertexs[0].y;
  for (size_t i = 0; i < numOfVertexs; ++i)
  {
    xMin = ((xMin > vertexs[i].x) ? vertexs[i].x : xMin);
    yMin = ((yMin > vertexs[i].y) ? vertexs[i].y : yMin);
    xMax = ((xMax < vertexs[i].x) ? vertexs[i].x : xMax);
    yMax = ((yMax < vertexs[i].y) ? vertexs[i].y : yMax);
  }

  return rectangle_t{(xMax - xMin), (yMax - yMin), point_t{(xMax + xMin) / 2, (yMax + yMin)/2}};
}

void rebdev::scaleFigure(point_t vertexs[], size_t numOfVertexs, const point_t & center, double k)
{
  for (size_t i = 0; i < numOfVertexs; ++i)
  {
    vertexs[i].x = (vertexs[i].x - center.x) * k + center.x;
    vertexs[i].y = (vertexs[i].y - center.y) * k + center.y;
  }
}
