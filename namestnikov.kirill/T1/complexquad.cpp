#include "complexquad.hpp"
#include "geometric_functions.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <algorithm>

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
}

double namestnikov::Complexquad::getArea() const
{
  point_t centerPoint = getIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_);
  double square = 0;
  square += getAreaOfTriangle(complexquadP1_, complexquadP4_, centerPoint);
  square += getAreaOfTriangle(complexquadP2_, complexquadP3_, centerPoint);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
  double mostLowPoint = std::min(complexquadP1_.y, std::min(complexquadP2_.y, std::min(complexquadP3_.y, complexquadP4_.y)));
  double mostHighPoint = std::max(complexquadP1_.y, std::max(complexquadP2_.y, std::max(complexquadP3_.y, complexquadP4_.y)));
  double mostLeftPoint = std::min(complexquadP1_.x, std::min(complexquadP2_.x, std::min(complexquadP3_.x, complexquadP4_.x)));
  double mostRightPoint = std::max(complexquadP1_.x, std::max(complexquadP2_.x, std::max(complexquadP3_.x, complexquadP4_.x)));
  double width = std::abs(mostRightPoint - mostLeftPoint);
  double height = std::abs(mostHighPoint - mostLowPoint);
  point_t position = {mostLeftPoint + (width / 2), mostLowPoint + (height / 2)};
  return {width, height, position};
}


void namestnikov::Complexquad::move(const point_t & p)
{
  point_t centerPoint = getIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_);
  const double dx = p.x - centerPoint.x;
  const double dy = p.y - centerPoint.y;
  complexquadP1_.x += dx;
  complexquadP1_.y += dy;
  complexquadP2_.x += dx;
  complexquadP2_.y += dy;
  complexquadP3_.x += dx;
  complexquadP3_.y += dy;
  complexquadP4_.x += dx;
  complexquadP4_.y += dy;
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
}

void namestnikov::Complexquad::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    point_t centerPoint = getIntersectionOfTwoLines(complexquadP1_, complexquadP2_, complexquadP3_, complexquadP4_);
    complexquadP1_.x = centerPoint.x + (complexquadP1_.x - centerPoint.x) * coefficient;
    complexquadP1_.y = centerPoint.y + (complexquadP1_.y - centerPoint.y) * coefficient;
    complexquadP2_.x = centerPoint.x + (complexquadP2_.x - centerPoint.x) * coefficient;
    complexquadP2_.y = centerPoint.y + (complexquadP2_.y - centerPoint.y) * coefficient;
    complexquadP3_.x = centerPoint.x + (complexquadP3_.x - centerPoint.x) * coefficient;
    complexquadP3_.y = centerPoint.y + (complexquadP3_.y - centerPoint.y) * coefficient;
    complexquadP4_.x = centerPoint.x + (complexquadP4_.x - centerPoint.x) * coefficient;
    complexquadP4_.y = centerPoint.y + (complexquadP4_.y - centerPoint.y) * coefficient;
  }
}
