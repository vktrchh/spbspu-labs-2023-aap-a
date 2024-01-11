#include "diamond.hpp"
#include "base-types.hpp"
#include <stdexcept>
#include <iostream>

arakelyan::Diamond::Diamond(const point_t fp, const point_t sp, const point_t tp):
  p1_(fp),
  p2_(sp),
  midPoint_(tp),
  p3_{(fp.x_), (tp.y_ - (fp.y_ - tp.y_))},
  p4_{(tp.x_ - (sp.x_ - tp.x_)),(sp.y_)}
{
  if ((fp.x_ != tp.x_) || (sp.y_ != tp.y_))
  {
    throw std::logic_error("Diagonals of the DIAMOND are not parallel to the axes!");
  }
}

double arakelyan::Diamond::getArea() const
{
  return std::abs(((p1_.y_ - p3_.y_) * (p2_.x_ - p4_.x_)) / 2.0);
}

rectangle_t arakelyan::Diamond::getFrameRect()
{
  double width = std::abs(p2_.x_ - midPoint_.x_) * 2.0;
  double height = std::abs(p1_.y_ - midPoint_.y_) * 2.0;
  rectangle_t data = {width, height, midPoint_};
  return data;
}

void arakelyan::Diamond::move(const point_t point)
{
  double dX = point.x_ - midPoint_.x_;
  double dY = point.y_ - midPoint_.y_;
  p1_.x_ += dX;
  p1_.y_ += dY;
  p2_.x_ += dX;
  p2_.y_ += dY;
  p3_.x_ += dX;
  p3_.y_ += dY;
  p4_.x_ += dX;
  p4_.y_ += dY;
  midPoint_ = point;
}

void arakelyan::Diamond::move(const double delX, const double delY)
{
  p1_.x_ += delX;
  p1_.y_ += delY;
  p2_.x_ += delX;
  p2_.y_ += delY;
  p3_.x_ += delX;
  p3_.y_ += delY;
  p4_.x_ += delX;
  p4_.y_ += delY;
  midPoint_.x_ += delX;
  midPoint_.y_ += delY;
}

void arakelyan::Diamond::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Diamond)");
  }
  rectangle_t dataOfFrameRect = getFrameRect();
  double widthWithScale = dataOfFrameRect.width_ * k;
  double heightWithScale = dataOfFrameRect.height_ * k;
  p1_.x_ = midPoint_.x_;
  p1_.y_ = midPoint_.y_ + (heightWithScale / 2.0);
  p2_.x_ = midPoint_.x_ + (widthWithScale / 2.0);
  p2_.y_ = midPoint_.y_;
  p3_.x_ = midPoint_.x_;
  p3_.y_ = midPoint_.y_ - (heightWithScale / 2.0);
  p4_.x_ = midPoint_.x_ - (widthWithScale / 2.0);
  p4_.y_ = midPoint_.y_;
}

arakelyan::Diamond::~Diamond()
{}
