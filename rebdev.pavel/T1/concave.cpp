#include "concave.hpp"
#include "figureFunction.hpp"

#include <cstddef>
#include <stdexcept>

rebdev::Concave::Concave(const point_t & firstVertex, const point_t & secondVertex,
  const point_t & thirdVertex, const point_t & fourthVertex):
  vertexs_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}
{
  point_t vertexs[4] = {firstVertex, secondVertex, thirdVertex, fourthVertex};
  bool isConcave = false;

  for (size_t i = 0; ((i < 4) && (!isConcave)); ++i)
  {
    if (!isTriangle(vertexs[i], vertexs[(i + 1) % 4], vertexs[(i + 2) % 4]))
    {
      continue;
    }

    double arr[3] = {0.0, 0.0, 0.0};
    for (size_t j = 0; j < 3; ++j)
    {
      point_t vertexsArr[3] = {vertexs[(i + j) % 4], vertexs[(i + 3) % 4], vertexs[(i + (j + 1) % 3) % 4]};

      arr[j] = (vertexsArr[0].x - vertexsArr[1].x) * (vertexsArr[2].y - vertexsArr[0].y);
      arr[j] -= (vertexsArr[2].x - vertexsArr[0].x) * (vertexsArr[0].y - vertexsArr[1].y);
    }

    bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
    identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

    if (identicalSigns)
    {
      vertexs_[0] = vertexs[i];
      vertexs_[1] = vertexs[(i + 1) % 4];
      vertexs_[2] = vertexs[(i + 3) % 4];
      vertexs_[3] = vertexs[(i + 2) % 4];
      isConcave = true;
    }
  }
  if (!isConcave)
  {
    throw std::logic_error("concave error");
  }
}

double rebdev::Concave::getArea() const
{
  double sum  = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    sum += (vertexs_[i].x * vertexs_[(i + 1) % 4].y) - (vertexs_[(i + 1) % 4].x * vertexs_[i].y);
  }
  sum /= 2;

  return std::abs(sum);
}

rebdev::rectangle_t rebdev::Concave::getFrameRect() const
{
  return getFrameRectangle(vertexs_, 4);
}

void rebdev::Concave::move(const point_t & point)
{
  move(point.x - vertexs_[2].x, point.y - vertexs_[2].y);
}

void rebdev::Concave::move(double x, double y)
{
  for (size_t i = 0; i < 4; ++i)
  {
    vertexs_[i].x += x;
    vertexs_[i].y += y;
  }
}

void rebdev::Concave::scale(double k)
{
  vertexs_[0] = scalePoint(vertexs_[0], vertexs_[2], k);
  vertexs_[1] = scalePoint(vertexs_[1], vertexs_[2], k);
  vertexs_[3] = scalePoint(vertexs_[3], vertexs_[2], k);
}

rebdev::point_t rebdev::Concave::scalePoint(const point_t & pointToScale, const point_t & centerPoint, double k)
{
  point_t scaledPoint = {(pointToScale.x - centerPoint.x) * k + centerPoint.x,
    (pointToScale.y - centerPoint.y) * k + centerPoint.y};
  return scaledPoint;
}

bool rebdev::isTriangle(const point_t & f, const point_t & s, const point_t & t)
{
    return (((t.x - f.x) / (s.x - f.x)) != ((t.y - f.y) / (s.y - f.y)));
}
