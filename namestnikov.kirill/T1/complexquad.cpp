#include "complexquad.hpp"
#include "geometric_functions.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>

namestnikov::Complexquad::Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4):
  complexquadP1_(p1),
  complexquadP2_(p2),
  complexquadP3_(p3),
  complexquadP4_(p4)
{
  if (!checkIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_))
  {
    throw std::invalid_argument("Lines are parallel in complexquad\n");
  }
  namestnikov::point_t points[4] = {complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_};
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
  centerPoint_ = getIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_);
}

double namestnikov::Complexquad::getArea() const
{
  double square = 0;
  square += getAreaOfTriangle(complexquadP1_, complexquadP4_, centerPoint_);
  square += getAreaOfTriangle(complexquadP2_, complexquadP3_, centerPoint_);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
  double mostLowPoint = complexquadP1_.y;
  double mostHighPoint = complexquadP1_.y;
  double mostLeftPoint = complexquadP1_.x;
  double mostRightPoint = complexquadP1_.x;
  namestnikov::point_t points[4] = {complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_};
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
  point_t center = getIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_);
  return center;
}

void namestnikov::Complexquad::move(const point_t & p)
{
  const double dx = p.x - centerPoint_.x;
  const double dy = p.y - centerPoint_.y;
  complexquadP1_.x += dx;
  complexquadP1_.y += dy;
  complexquadP2_.x += dx;
  complexquadP2_.y += dy;
  complexquadP3_.x += dx;
  complexquadP3_.y += dy;
  complexquadP4_.x += dx;
  complexquadP4_.y += dy;
  centerPoint_.x += dx;
  centerPoint_.y += dy;
}

void namestnikov::Complexquad::move(const double dx, const double dy)
{
  complexquadP1_.x += dx;
  complexquadP1_.y += dy;
  complexquadP2_.x += dx;
  complexquadP2_.y += dy;
  complexquadP3_.x += dx;
  complexquadP3_.y += dy;
  complexquadP4_.x += dx;
  complexquadP4_.y += dy;
  centerPoint_.x += dx;
  centerPoint_.y += dy;
}

void namestnikov::Complexquad::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    complexquadP1_.x = centerPoint_.x + (complexquadP1_.x - centerPoint_.x) * coefficient;
    complexquadP1_.y = centerPoint_.y + (complexquadP1_.y - centerPoint_.y) * coefficient;
    complexquadP2_.x = centerPoint_.x + (complexquadP2_.x - centerPoint_.x) * coefficient;
    complexquadP2_.y = centerPoint_.y + (complexquadP2_.y - centerPoint_.y) * coefficient;
    complexquadP3_.x = centerPoint_.x + (complexquadP3_.x - centerPoint_.x) * coefficient;
    complexquadP3_.y = centerPoint_.y + (complexquadP3_.y - centerPoint_.y) * coefficient;
    complexquadP4_.x = centerPoint_.x + (complexquadP4_.x - centerPoint_.x) * coefficient;
    complexquadP4_.y = centerPoint_.y + (complexquadP4_.y - centerPoint_.y) * coefficient;
  }
}

