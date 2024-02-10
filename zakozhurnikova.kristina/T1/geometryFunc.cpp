#include "geometryFunc.hpp"
#include <limits>
#include <cmath>
#include <stdexcept>

zakozhurnikova::point_t zakozhurnikova::getComplexquadCenter(const point_t* points)
{
  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double determinant = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
  double determinantX = (x2 - x1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (x4 - x3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  double determinantY = (y2 - y1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (y4 - y3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  point_t center(-determinantX / determinant, -determinantY / determinant);
  return center;
}

bool zakozhurnikova::hasEqualPoints(const point_t* points, size_t size)
{
  for (size_t i = 0; i < size - 1; ++i)
  {
    for (size_t j = i + 1; j < size; ++j)
    {
      if (points[i] == points[j])
      {
        return true;
      }
    }
  }

  return false;
}

bool zakozhurnikova::isPointOnLine(double x1, double y1, double x2, double y2, double x, double y)
{
  double leftSide = (y - y1) * (x2 - x1);
  double rightSide = (x - x1) * (y2 - y1);
  return leftSide == rightSide;
}

bool zakozhurnikova::hasContentPoint(const point_t* points, size_t size)
{
  for (size_t i = 0; i < size - 2; ++i)
  {
    for (size_t j = i + 2; j < size; ++j)
    {
      if (isPointOnLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, points[i + 2].x, points[i + 2].y))
      {
        return true;
      }
    }
  }
  return false;
}

bool zakozhurnikova::hasIntersection(const point_t* points)
{
  const size_t POINTS_COUNT = 4;
  if (hasEqualPoints(points, POINTS_COUNT)  || hasContentPoint(points, POINTS_COUNT))
  {
    return false;
  }

  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (std::abs(denominator) <= 1e-6)
  {
    return false;
  }
  double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
  double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;
  if (x < std::min(x1, x2) || x > std::max(x1, x2) || x < std::min(x3, x4) || x > std::max(x3, x4) ||
      y < std::min(y1, y2) || y > std::max(y1, y2) || y < std::min(y3, y4) || y > std::max(y3, y4))
  {
    return false;
  }
  return true;
}

void zakozhurnikova::initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree)
{
  const double EPSILON = 1e-6;
  double sqrA = std::pow(pointOne.getDistance(pointTwo), 2.0);
  double sqrB = std::pow(pointOne.getDistance(pointThree), 2.0);
  double sqrC = std::pow(pointTwo.getDistance(pointThree), 2.0);
  if(std::abs(sqrA - sqrB - sqrC) <= EPSILON)
  {
    points[0] = pointThree;
    points[1] = pointTwo;
    points[2] = pointOne;
    return;
  }
  else if(std::abs(sqrB - sqrA - sqrC) <= EPSILON)
  {
    points[0] = pointTwo;
    points[1] = pointOne;
    points[2] = pointThree;
    return;
  }
  else if(std::abs(sqrC - sqrA - sqrB) <= EPSILON)
  {
    points[0] = pointOne;
    points[1] = pointTwo;
    points[2] = pointThree;
    return;
  }
  else
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }
}
