#include "diamond.hpp"
#include "base-types.hpp"
#include <stdexcept>

arakelyan::Diamond::Diamond(const point_t fp, const point_t sp, const point_t tp):
  p1_(fp),
  p2_(sp),
  midPoint_(tp),
  p3_{(fp.x), (tp.y - (fp.y - tp.y))},
  p4_{(tp.x - (sp.x - tp.x)),(sp.y)}
{
  if ((fp.x != tp.x) || (sp.y != tp.y))
  {
    throw std::logic_error("Diagonals of the DIAMOND are not parallel to the axes!");
  }
}

double arakelyan::Diamond::getArea() const
{
  return std::abs(((p1_.y - p3_.y) * (p2_.x - p4_.x)) / 2.0);
}

arakelyan::rectangle_t arakelyan::Diamond::getFrameRect() const
{
  double width = std::abs(p2_.x - midPoint_.x) * 2.0;
  double height = std::abs(p1_.y - midPoint_.y) * 2.0;
  rectangle_t data = {width, height, midPoint_};
  return data;
}

void arakelyan::Diamond::move(const point_t point)
{
  double dX = point.x - midPoint_.x;
  double dY = point.y - midPoint_.y;
  p1_.x += dX;
  p1_.y += dY;
  p2_.x += dX;
  p2_.y += dY;
  p3_.x += dX;
  p3_.y += dY;
  p4_.x += dX;
  p4_.y += dY;
  midPoint_ = point;
}

void arakelyan::Diamond::move(const double delX, const double delY)
{
  p1_.x += delX;
  p1_.y += delY;
  p2_.x += delX;
  p2_.y += delY;
  p3_.x += delX;
  p3_.y += delY;
  p4_.x += delX;
  p4_.y += delY;
  midPoint_.x += delX;
  midPoint_.y += delY;
}

void arakelyan::Diamond::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Diamond)");
  }
  rectangle_t dataOfFrameRect = getFrameRect();
  double widthWithScale = dataOfFrameRect.width * k;
  double heightWithScale = dataOfFrameRect.height * k;
  p1_.x = midPoint_.x;
  p1_.y = midPoint_.y + (heightWithScale / 2.0);
  p2_.x = midPoint_.x + (widthWithScale / 2.0);
  p2_.y = midPoint_.y;
  p3_.x = midPoint_.x;
  p3_.y = midPoint_.y - (heightWithScale / 2.0);
  p4_.x = midPoint_.x - (widthWithScale / 2.0);
  p4_.y = midPoint_.y;
}

arakelyan::Diamond::~Diamond()
{}
