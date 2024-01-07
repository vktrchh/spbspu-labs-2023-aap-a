#include "rectangle.hpp"
#include <stdexcept>

namespace marishin
{
  Rectangle::Rectangle(const point_t lowerLeftCorner, const point_t topRightCorner):
    lowerLeftCorner_(lowerLeftCorner),
    topRightCorner_(topRightCorner)
  {
    if (!(((lowerLeftCorner_.x < topRightCorner_.x) && (lowerLeftCorner_.y < topRightCorner_.y))
      || ((lowerLeftCorner_.x > topRightCorner_.x) && (lowerLeftCorner_.y > topRightCorner_.y))))
    {
      throw std::logic_error("Invalid rectangle");
    }
  }

  Rectangle::~Rectangle()
  {
  }

  double Rectangle::getArea()
  {
    return (std::abs((lowerLeftCorner_.x - topRightCorner_.x) * (lowerLeftCorner_.y - topRightCorner_.y)));
  }

  rectangle_t Rectangle::getFrameRect()
  {
    point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
    double width_t = std::abs(lowerLeftCorner_.x - topRightCorner_.x);
    double height_t = std::abs(lowerLeftCorner_.y - topRightCorner_.y);
    return { pos, width_t, height_t };
  }

  void Rectangle::move(const point_t newPos)
  {
    point_t pos = { ((lowerLeftCorner_.x + topRightCorner_.x) / 2), ((lowerLeftCorner_.y + topRightCorner_.y) / 2) };
    move(newPos.x - pos.x, newPos.y - pos.y);
  }

  void Rectangle::move(const double dx, const double dy)
  {
    lowerLeftCorner_.x += dx;
    lowerLeftCorner_.y += dy;
    topRightCorner_.x += dx;
    topRightCorner_.y += dy;
  }

  
}

