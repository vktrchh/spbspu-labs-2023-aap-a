#include <stdexcept>
#include "diamond.hpp"
#include "base-types.hpp"

arakelyan::Diamond::Diamond(const point_t fp, const point_t sp, const point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp)
{
  if (!(p1_.y == p2_.y || p1_.y == p3_.y || p2_.y == p3_.y))
  {
    throw std::logic_error("Diagonals of the DIAMOND are not parallel to the axes!");
  }
}

double arakelyan::Diamond::getArea() const
{
  rectangle_t dataOfFrameRect = getFrameRect();
  return std::abs((dataOfFrameRect.height * dataOfFrameRect.width) / 2.0);
}

arakelyan::rectangle_t arakelyan::Diamond::getFrameRect() const
{
  double width = 0;
  if (p1_.y == p2_.y)
  {
    width = std::abs(p2_.x - p1_.x) * 2.0;
  }
  else if (p1_.y == p3_.y)
  {
    width = std::abs(p3_.x - p1_.x) * 2.0;
  }
  else
  {
    width = std::abs(p2_.x - p3_.x) * 2.0;
  }

  double height = 0;
  if (p2_.x == p3_.x)
  {
    height = std::abs(p3_.y - p2_.y) * 2.0;
  }
  else if (p1_.x == p2_.x)
  {
    height = std::abs(p3_.y - p1_.y) * 2.0;
  }
  else
  {
    height = std::abs(p1_.y - p2_.y) * 2.0;
  }

  point_t midPoint = {0, 0};

  if (p2_.x == p3_.x && p2_.y == p1_.y)
  {
    midPoint = p2_;
  }
  else if (p1_.y == p2_.y && p1_.x == p3_.x)
  {
    midPoint = p1_;
  }
  else
  {
    midPoint = p3_;
  }

  rectangle_t dataOfFrameRect = {width, height, midPoint};
  return dataOfFrameRect;
}

void arakelyan::Diamond::move(const point_t point)
{
  rectangle_t data = getFrameRect();
  double delX = point.x - data.pos.x;
  double delY = point.y - data.pos.y;
  move(delX, delY);
}

void arakelyan::Diamond::move(const double delX, const double delY)
{
  point_t * pointsArray[3] = {&p1_,&p2_,&p3_};
  for (size_t i = 0; i < 3; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void arakelyan::Diamond::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Diamond)");
  }
  rectangle_t dataOfFrameRect = getFrameRect();
  point_t * pointsArray[3] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    pointsArray[i]->x = dataOfFrameRect.pos.x + ((pointsArray[i]->x - dataOfFrameRect.pos.x) * k);
    pointsArray[i]->y = dataOfFrameRect.pos.y +((pointsArray[i]-> x - dataOfFrameRect.pos.y) * k);
  }
}
