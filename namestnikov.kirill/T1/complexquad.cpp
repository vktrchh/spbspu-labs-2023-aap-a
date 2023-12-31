#include "complexquad.hpp"
#include "geometric_functions.hpp"
#include <stdexcept>

namestnikov::Complexquad::Complexquad(point_t * points, size_t size):
  complexquadPoints_(points),
  complexquadSize_(size)
{
  if (complexquadSize_ != 4)
  {
    throw std::invalid_argument("It should be 4 points to describe Complexquad\n";
  }
  else
  {
    for (size_t i = 0; i < size; ++i)
    {
      for (size_t j = i + 1; j < size; ++j)
      {
        if ((complexquadPoints_[i].x == complexquadPoints_[j].x) && (complexquadPoints_[i].y == complexquadPoints_[j].y))
        {
          throw std::invalid_argument("It shouldn't be 2 same points in complexquad\n";
        }
      }
    }
  }
}

double namestnikov::Complexquad::getArea() const
{
  point_t centerPoint = getIntersectionOftwoLines(complexquadPoints_);
  double square = 0;
  square += getAreaOfTriangle(complexquadPoints_[0], complexquadPoints_[3], centerPoint);
  square += getAreaOfTriangle(complexquadPoints_[1], complexquadPoints_[2], centerPoint);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
}


void namestnikov::Complexquad::move(const point_t & p)
{
  
}

void namestnikov::Complexquad::move(const double dx, const double dy)
{

}

void namestnikov::Complexquad::scale(const double coefficient)
{

}
