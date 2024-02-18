#include "concave.hpp"
#include <cstddef>
#include <stdexcept>
#include "figureFunction.hpp"

rebdev::Concave::Concave(const point_t & firstVertex, const point_t & secondVertex,
  const point_t & thirdVertex, const point_t & fourthVertex):
  vertexes_{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}
{
  point_t vertexes[4] = {firstVertex, secondVertex, thirdVertex, fourthVertex};
  bool isConcave = false;

  for (size_t i = 0; ((i < 4) && (!isConcave)); ++i)
  {
    if (!isTriangle(vertexes[i], vertexes[(i + 1) % 4], vertexes[(i + 2) % 4]))
    {
      continue;
    }

    double arr[3] = {0.0, 0.0, 0.0};
    for (size_t j = 0; j < 3; ++j)
    {
      point_t vertexesArr[3] = {vertexes[(i + j) % 4], vertexes[(i + 3) % 4], vertexes[(i + (j + 1) % 3) % 4]};

      arr[j] = (vertexesArr[0].x - vertexesArr[1].x) * (vertexesArr[2].y - vertexesArr[0].y);
      arr[j] -= (vertexesArr[2].x - vertexesArr[0].x) * (vertexesArr[0].y - vertexesArr[1].y);
    }

    bool identicalSigns = ((arr[0] > 0) && (arr[1] > 0) && (arr[2] > 0));
    identicalSigns = (identicalSigns || ((arr[0] < 0) && (arr[1] < 0) && (arr[2] < 0)));

    if (identicalSigns)
    {
      vertexes_[0] = vertexes[i];
      vertexes_[1] = vertexes[(i + 1) % 4];
      vertexes_[2] = vertexes[(i + 3) % 4];
      vertexes_[3] = vertexes[(i + 2) % 4];
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
    sum += (vertexes_[i].x * vertexes_[(i + 1) % 4].y) - (vertexes_[(i + 1) % 4].x * vertexes_[i].y);
  }
  sum /= 2;

  return std::abs(sum);
}

rebdev::rectangle_t rebdev::Concave::getFrameRect() const
{
  return getFrameRectangle(vertexes_, 4);
}

void rebdev::Concave::move(const point_t & point)
{
  move(point.x - vertexes_[2].x, point.y - vertexes_[2].y);
}

void rebdev::Concave::move(double x, double y)
{
  for (size_t i = 0; i < 4; ++i)
  {
    vertexes_[i].x += x;
    vertexes_[i].y += y;
  }
}

void rebdev::Concave::scale(double k)
{
  vertexes_[0] = scalePoint(vertexes_[0], vertexes_[2], k);
  vertexes_[1] = scalePoint(vertexes_[1], vertexes_[2], k);
  vertexes_[3] = scalePoint(vertexes_[3], vertexes_[2], k);
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
