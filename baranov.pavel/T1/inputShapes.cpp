#include "inputShapes.hpp"
#include "inputString.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"
#include <string>
#include <stdexcept>

baranov::Shape ** baranov::expandShapes(baranov::Shape ** shapes, const size_t size, const size_t newSize)
{
  baranov::Shape ** result = new baranov::Shape*[newSize];
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = shapes[i];
  }
  return result;
}

baranov::Shape * baranov::parseRectangle(const char * string)
{
  double rectParameters[4]{};
  size_t pos = 0;
  string += 9;
  for (size_t i = 0; i < 4; ++i)
  {
    rectParameters[i] = std::stod(string, & pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
  baranov::point_t ldCorner = { rectParameters[0], rectParameters[1] };
  baranov::point_t ruCorner = { rectParameters[2], rectParameters[3] };
  return new baranov::Rectangle(ldCorner, ruCorner);
}

baranov::Shape * baranov::parseRing(const char * string)
{
  double ringParameters[4]{};
  size_t pos = 0;
  string += 4;
  for (size_t i = 0; i < 4; ++i)
  {
    ringParameters[i] = std::stod(string, & pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid ring parameters");
  }
  baranov::point_t center = { ringParameters[0], ringParameters[1] };
  return new baranov::Ring(center, ringParameters[2], ringParameters[3]);
}

baranov::Shape * baranov::parseEllipse(const char * string)
{
  double ellipseParameters[4]{};
  size_t pos = 0;
  string += 7;
  for (size_t i = 0; i < 4; ++i)
  {
    ellipseParameters[i] = std::stod(string, & pos);
    string += pos;
  }
  if (*string != '\0')
  {
    throw std::invalid_argument("Invalid ellipse parameters");
  }
  baranov::point_t center = { ellipseParameters[0], ellipseParameters[1] };
  return new baranov::Ellipse(center, ellipseParameters[2], ellipseParameters[3]);
}
