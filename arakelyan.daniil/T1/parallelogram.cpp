#include "parallelogram.hpp"
#include "base-types.hpp"
#include <stdexcept>

arakelyan::Parallelogram::Parallelogram(point_t fp, point_t sp, point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp)
{
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::logic_error("The provided points do not form a parallelogram!");
  }
  if ((p1_.x == 0) && (p1_.y == 0) && (p2_.x == 0) && (p2_.y == 0) && (p3_.x == 0) && (p3_.y == 0))
  {
    throw std::logic_error("Invalid points for parallelogram!");
  }
};

double arakelyan::Parallelogram::getArea() const
{
  return std::abs((p3_.y - p1_.y) * (p2_.x - p1_.x));
}

arakelyan::rectangle_t arakelyan::Parallelogram::getFrameRect() const
{
  double width = std::abs(p2_.x - p1_.x) + std::abs(p2_.x - p3_.x);
  double height = 0;
  if (p2_.y == p1_.y)
  {
    height = std::abs(p3_.y - p2_.y);
  }
  else
  {
    height = std::abs(p2_.y - p1_.y);
  }

  point_t midPointOfRect = {0,0};

  if (p1_.x <= p2_.x && p1_.x <= p3_.x)
  {
    midPointOfRect.x = p1_.x + (width / 2.0);
  }
  else if (p2_.x <= p1_.x && p2_.x <= p3_.x)
  {
    midPointOfRect.x = p2_.x + (width / 2.0);
  }
  else
  {
    midPointOfRect.x = p3_.x + (width / 2.0);
  }

  if (p1_.y > p2_.y || p1_.y > p3_.y)
  {
    midPointOfRect.y = p1_.y - (height / 2.0);
  }
  else
  {
    midPointOfRect.y = p1_.y + (height / 2.0);
  }
  rectangle_t data = {width, height, midPointOfRect};
  return data;
}


void arakelyan::Parallelogram::move(const point_t point)
{
  rectangle_t rectOfParal = getFrameRect();
  double delX = point.x - rectOfParal.pos.x;
  double delY = point.y - rectOfParal.pos.y;
  p1_.x += delX;
  p1_.y += delY;
  p2_.x += delX;
  p2_.y += delY;
  p3_.x += delX;
  p3_.y += delY;
}

void arakelyan::Parallelogram::move(const double delX, const double delY)
 {
   p1_.x += delX;
   p1_.y += delY;
   p2_.x += delX;
   p2_.y += delY;
   p3_.x += delX;
   p3_.y += delY;
 }

void arakelyan::Parallelogram::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Parallelogram)");
  }
  rectangle_t rectOfParal = getFrameRect();
  // double widthWithScale = rectOfParal.width * k;
  // double heightWithScale = rectOfParal.height * k;
  p1_.x = rectOfParal.pos.x + ((p1_.x - rectOfParal.pos.x) * k);
  p1_.y = rectOfParal.pos.y + ((p1_.y - rectOfParal.pos.y) * k);
  p2_.x = rectOfParal.pos.x + ((p2_.x - rectOfParal.pos.x) * k);
  p2_.y = rectOfParal.pos.y + ((p2_.y - rectOfParal.pos.y) * k);
  p3_.x = rectOfParal.pos.x + ((p3_.x - rectOfParal.pos.x) * k);
  p3_.y = rectOfParal.pos.y + ((p3_.y - rectOfParal.pos.y) * k);
}

arakelyan::Parallelogram::~Parallelogram()
{};
