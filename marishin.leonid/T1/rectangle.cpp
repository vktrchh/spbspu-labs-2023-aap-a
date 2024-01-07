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

  
}

