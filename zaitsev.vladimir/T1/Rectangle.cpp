#include "Rectangle.h"
#include <stdexcept>
#include "base-types.h"

namespace zaitsev
{
  Rectangle::Rectangle(const point_t& left_ñorner, const point_t& right_ñorner) :
    left_ñorner_(left_ñorner),
    right_ñorner_(right_ñorner)
  {
    if (left_ñorner.x > right_ñorner.x || left_ñorner.y > right_ñorner.y)
    {
      throw std::invalid_argument("Invalid order of points");
    }
  }

  double Rectangle::getArea() const
  {
    return (right_ñorner_.x - left_ñorner_.x) * (right_ñorner_.y - left_ñorner_.y);
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    double width = right_ñorner_.x - left_ñorner_.x;
    double height = right_ñorner_.y - left_ñorner_.y;
    point_t pos = { left_ñorner_.x + width / 2, left_ñorner_.y + height / 2 };
    return { width, height, pos };
  }

  void Rectangle::move(const point_t& dest_pos)
  {
    point_t center = getCenter();
    point_t diff = { dest_pos.x - center.x, dest_pos.y - center.y };
    left_ñorner_.x += diff.x;
    left_ñorner_.y += diff.y;
    right_ñorner_.x += diff.x;
    right_ñorner_.y += diff.y;
  }

  void Rectangle::move(double x_shift, double y_shift)
  {
    left_ñorner_.x += x_shift;
    left_ñorner_.y += y_shift;
    right_ñorner_.x += x_shift;
    right_ñorner_.y += y_shift;
  }

  point_t Rectangle::getCenter() const
  {
    double width = right_ñorner_.x - left_ñorner_.x;
    double height = right_ñorner_.y - left_ñorner_.y;
    return { left_ñorner_.x + width / 2, left_ñorner_.y + height / 2 };
  }

  void Rectangle::scale(double factor)
  {
    if (factor <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    point_t center = getCenter();
    left_ñorner_.x = 2 * left_ñorner_.x - center.x;
    right_ñorner_.x = 2 * right_ñorner_.x - center.x;
    left_ñorner_.y = 2 * left_ñorner_.y - center.y;
    right_ñorner_.y = 2 * right_ñorner_.y - center.y;
  }
}
