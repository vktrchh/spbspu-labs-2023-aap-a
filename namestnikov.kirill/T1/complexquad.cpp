#include "complexquad.hpp"
#include "geometric_functions.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <algorithm>

namestnikov::Complexquad::Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4):
  point1_(p1),
  point2_(p2),
  point3_(p3),
  point4_(p4)
{
  if (!checkIntersectionOfTwoLines(point1_, point2_, point3_, point4_))
  {
    throw std::invalid_argument("Lines are parallel in complexquad\n");
  }
  namestnikov::point_t points[4] = {point1_, point2_, point3_, point4_};
  for (size_t i = 0; i < 4; ++i)
  {
    for (size_t j = i + 1; j < 4; ++j)
    {
      if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
      {
        throw std::invalid_argument("There shouldn't be 2 same points in complexquad\n");
      }
    }
  }
}

double namestnikov::Complexquad::getArea() const
{
  double square = 0;
  point_t centerPoint = getIntersectionOfTwoLines(point1_, point2_, point3_, point4_);
  square += getAreaOfTriangle(point1_, point4_, centerPoint);
  square += getAreaOfTriangle(point2_, point3_, centerPoint);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
  double mostLowPoint = point1_.y;
  double mostHighPoint = point1_.y;
  double mostLeftPoint = point1_.x;
  double mostRightPoint = point1_.x;
  namestnikov::point_t points[4] = {point1_, point2_, point3_, point4_};
  for (size_t i = 1; i < 4; ++i)
  {
    mostLowPoint = std::min(mostLowPoint, points[i].y);
    mostHighPoint = std::max(mostHighPoint, points[i].y);
    mostLeftPoint = std::min(mostLeftPoint, points[i].x);
    mostRightPoint = std::max(mostRightPoint, points[i].x);
  }
  double width = std::abs(mostRightPoint - mostLeftPoint);
  double height = std::abs(mostHighPoint - mostLowPoint);
  point_t position = {mostLeftPoint + (width / 2), mostLowPoint + (height / 2)};
  return {width, height, position};
}

namestnikov::point_t namestnikov::Complexquad::getCenter() const
{
  return getIntersectionOfTwoLines(point1_, point2_, point3_, point4_);
}

void namestnikov::Complexquad::move(const point_t & p)
{
  point_t centerPoint = getIntersectionOfTwoLines(point1_, point2_, point3_, point4_);
  const double dx = p.x - centerPoint.x;
  const double dy = p.y - centerPoint.y;
  this->move(dx, dy);
}

void namestnikov::Complexquad::move(const double dx, const double dy)
{
  point1_.x += dx;
  point1_.y += dy;
  point2_.x += dx;
  point2_.y += dy;
  point3_.x += dx;
  point3_.y += dy;
  point4_.x += dx;
  point4_.y += dy;
}

void namestnikov::Complexquad::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    point_t centerPoint = getIntersectionOfTwoLines(point1_, point2_, point3_, point4_);
    point1_.x = centerPoint.x + (point1_.x - centerPoint.x) * coefficient;
    point1_.y = centerPoint.y + (point1_.y - centerPoint.y) * coefficient;
    point2_.x = centerPoint.x + (point2_.x - centerPoint.x) * coefficient;
    point2_.y = centerPoint.y + (point2_.y - centerPoint.y) * coefficient;
    point3_.x = centerPoint.x + (point3_.x - centerPoint.x) * coefficient;
    point3_.y = centerPoint.y + (point3_.y - centerPoint.y) * coefficient;
    point4_.x = centerPoint.x + (point4_.x - centerPoint.x) * coefficient;
    point4_.y = centerPoint.y + (point4_.y - centerPoint.y) * coefficient;
  }
}
