#include "rectangle.hpp"

agarkov::Rectangle::Rectangle(const agarkov::point_t left_bottom, constag arkov::point_t right_top):
  left_bottom_(left_bottom),
  right_top_(right_top)
{
  if (!isCorrectRectangle())
  {
    throw std::invalid_argument("Incorrect rectangle argument");
  }
}

bool agarkov::Rectangle::isCorrectRectangle() const
{
  return ((left_bottom_.x < right_top_.x) && (left_bottom_.y < right_top_.y));
}
