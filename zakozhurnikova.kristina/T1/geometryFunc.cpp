#include "geometryFunc.hpp"
#include <limits>
#include <cmath>
#include <stdexcept>

zakozhurnikova::point_t zakozhurnikova::scaleShift(double k, const point_t& p1, const point_t& p2)
{
  double shiftX = p2.x + k * (p1.x - p2.x);
  double shiftY = p2.y + k * (p1.y - p2.y);
  return point_t{shiftX, shiftY};
}

double zakozhurnikova::getDistance(const point_t& p1, const point_t& p2)
{
  double distance = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y));
  return distance;
}

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
  point_t center = {-determinantX / determinant, -determinantY / determinant};
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

bool zakozhurnikova::isPointOnLine(const point_t& p1, const point_t& p2, const point_t& p)
{
  double leftSide = (p.y - p1.y) * (p2.x - p1.x);
  double rightSide = (p.x - p1.x) * (p2.y - p1.y);
  return leftSide == rightSide;
}

bool zakozhurnikova::hasContentPoint(const point_t* points, size_t size)
{
  for (size_t i = 0; i < size - 2; ++i)
  {
    for (size_t j = i + 2; j < size; ++j)
    {
      if (isPointOnLine(points[i], points[i + 1], points[i + 2]))
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
  const bool IS_DOT_OUT_LINE_FIRST = x < std::min(x1, x2) || x > std::max(x1, x2) || x < std::min(x3, x4) || x > std::max(x3, x4);
  const bool IS_DOT_OUT_LINE_SECOND = y < std::min(y1, y2) || y > std::max(y1, y2) || y < std::min(y3, y4) || y > std::max(y3, y4);
  return  !(IS_DOT_OUT_LINE_FIRST || IS_DOT_OUT_LINE_SECOND);
}

void zakozhurnikova::initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree)
{
  const double EPSILON = 1e-6;
  double sqrA = std::pow(getDistance(pointOne, pointTwo), 2.0);
  double sqrB = std::pow(getDistance(pointOne, pointThree), 2.0);
  double sqrC = std::pow(getDistance(pointTwo, pointThree), 2.0);
  if (std::abs(sqrA - sqrB - sqrC) <= EPSILON)
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

bool zakozhurnikova::arePointsOnAxis(const point_t& p1, const point_t& p2, const point_t& p3)
{
  const double EPSILON = 1e-6;
  const bool isTriangleOnAxisFirst = (std::abs(p1.x - p2.x) <= EPSILON) && (std::abs(p1.y - p3.y) <= EPSILON);
  const bool isTriangleOnAxixSecond = (std::abs(p1.x - p3.x) <= EPSILON) && (std::abs(p1.y - p2.y) <= EPSILON);
  return isTriangleOnAxisFirst || isTriangleOnAxixSecond;
}

void zakozhurnikova::operator+=(point_t& dest, const point_t& src)
{
  dest.x += src.x;
  dest.y += src.y;
}

zakozhurnikova::point_t zakozhurnikova::operator+(const point_t& p1, const point_t& p2)
{
  return point_t{p1.x + p2.x, p1.y + p2.y};
}

zakozhurnikova::point_t zakozhurnikova::operator-(const point_t& p1, const point_t& p2)
{
  return point_t{p1.x - p2.x, p1.y - p2.y};
}

zakozhurnikova::point_t zakozhurnikova::operator*(const point_t& p1, double k)
{
  return point_t{p1.x * k, p1.y * k};
}

zakozhurnikova::point_t zakozhurnikova::operator/(const point_t& p1, double k)
{
  if (k == 0.0)
  {
    throw std::invalid_argument("Division by ZERO.");
  }
  return point_t{p1.x / k, p1.y / k};
}

bool zakozhurnikova::operator==(const point_t& p1, const point_t& p2)
{
  return p1.x == p2.x && p1.y == p2.y;
}
