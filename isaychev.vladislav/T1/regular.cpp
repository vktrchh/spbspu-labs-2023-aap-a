#include "regular.hpp"
#include <cmath>

isaychev::Regular::Regular(const coint_t & p1, const point_t & p2, const point_t & p3):
  center(p1),
  closePnt(p2),
  distPnt(p3)
{}

//передавать точки определенным образом(определять где гип. при создании, что по сути и так нужно сделать)
double isaychev::Regular::getArea() const
{
  double outRad = 0, bottom = 0, radX = 0, radY = 0;
  radX = (distPnt.x_ - closePnt.x_) * (distPnt.x_ - closePnt.x_);
  radY = (distPnt.y_ - closePnt.y_) * (distPnt.y_ - closePnt.y_);
  bottom = std::sqrt(radX + radY);
  radX = (center.x_ - closePnt.x_) * (center.x_ - closePnt.x_);
  radY = (center.y_ - closePnt.y_) * (center.y_ - closePnt.y_);
  inRad = std::sqrt(radX + radY);
  double numOfSides = 3.1415926535 / std::atan(bottom / inRad);
  return bottom * inRad * numOfSides;
}

isaychev::rectangle_t isaychev::Regular::getFrameRect() const
{
  
}

void isaychev::Regular::move(const double dX, const double dY)
{
  
}

void isaychev::Regular::move(const point_t & newPos)
{
  
}

void isaychev::Regular::scale(const double coeff)
{
  
}
