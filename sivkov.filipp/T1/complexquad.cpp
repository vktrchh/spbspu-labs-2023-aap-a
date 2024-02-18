#include "complexquad.hpp"
#include "othersFun.hpp"
#include <stdexcept>

sivkov::Complexquad::Complexquad(const point_t& ver1, const point_t& ver2, const point_t& ver3, const point_t& ver4) :
  cqVer1_(ver1),
  cqVer2_(ver2),
  cqVer3_(ver3),
  cqVer4_(ver4)
{
  if (!areSegmentsIntersecting(ver1, ver2, ver3, ver4))
  {
    throw std::invalid_argument("Sides of the complex quad intersect. Invalid configuration.");
  }
}

double sivkov::Complexquad::getArea() const
{
  point_t center = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);

  double ab = findLine(cqVer1_, center);
  double ac = findLine(cqVer4_, center);
  double cb = findLine(cqVer1_, cqVer4_);
  double halfPer = (ab + ac + cb) / 2.0;
  double area1 = std::sqrt(halfPer * (halfPer - ab) * (halfPer - ac) * (halfPer - cb));

  double ab1 = findLine(cqVer2_, center);
  double ac1 = findLine(cqVer3_, center);
  double cb1 = findLine(cqVer2_, cqVer3_);
  double halfPer2 = (ab1 + ac1 + cb1) / 2.0;
  double area2 = std::sqrt(halfPer2 * (halfPer2 - ab1) * (halfPer2 - ac1) * (halfPer2 - cb1));

  return area1 + area2;
}

sivkov::rectangle_t sivkov::Complexquad::getFrameRect() const
{
  double xmin = std::min({ cqVer1_.x, cqVer2_.x, cqVer3_.x, cqVer4_.x });
  double xmax = std::max({ cqVer1_.x, cqVer2_.x, cqVer3_.x, cqVer4_.x });
  double ymin = std::min({ cqVer1_.y, cqVer2_.y, cqVer3_.y, cqVer4_.y });
  double ymax = std::max({ cqVer1_.y, cqVer2_.y, cqVer3_.y, cqVer4_.y });

  return rectangle_t{ point_t{xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2} ,(xmax - xmin), (ymax - ymin) };
}

void sivkov::Complexquad::move(point_t newPos)
{
  point_t center = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  const double dx = newPos.x - center.x;
  const double dy = newPos.y - center.y;
  move(dx, dy);
}

void sivkov::Complexquad::move(const double dx, const double dy)
{
  cqVer1_.x += dx;
  cqVer1_.y += dy;
  cqVer2_.x += dx;
  cqVer2_.y += dy;
  cqVer3_.x += dx;
  cqVer3_.y += dy;
  cqVer4_.x += dx;
  cqVer4_.y += dy;
}

void sivkov::Complexquad::scale(const double k)
{
  point_t centerPoint = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  cqVer1_ = doCenterShift(k, centerPoint, cqVer1_);
  cqVer2_ = doCenterShift(k, centerPoint, cqVer2_);
  cqVer3_ = doCenterShift(k, centerPoint, cqVer3_);
  cqVer4_ = doCenterShift(k, centerPoint, cqVer4_);
}
