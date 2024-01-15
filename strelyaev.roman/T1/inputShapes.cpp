#include "inputShapes.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>

Shape * inputRectangle(const char string[])
{
  const char * coords_string = string + 10;
  double coords_array[4]{};
  size_t pos = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
  }
  if (*coords_array != '\0')
  {
    throw std::invalid_argument("Invalid RECTANGLE arguments");
  }
  point_t p1 = {coords_array[0], coords_array[1]};
  point_t p2 = {coords_array[2], coords_array[3]};
  return new Rectangle(p1, p2);
}
Shape * inputTriangle(const char string[])
{
  const char * coords_string = string + 9;
  double coords_array[6]{};
  size_t pos = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
  }
  if (*coords_array != '\0')
  {
    throw std::invalid_argument("Invalid TRIANGLE arguments");
  }
  point_t p1 = {coords_array[0], coords_array[1]};
  point_t p2 = {coords_array[2], coords_array[3]};
  point_t p3 = {coords_array[4], coords_array[5]};
  return new Triangle(p1, p2, p3);
}

Shape * inputParallelogram(const char string[])
{
  const char * coords_string = string + 14;
  double coords_array[6]{};
  size_t pos = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coords_array[i] = std::stod(coords_string, std::addressof(pos));
  }
  if (*coords_array != '\0')
  {
    throw std::invalid_argument("Invalid PARALLELOGRAM arguments");
  }
  point_t p1 = {coords_array[0], coords_array[1]};
  point_t p2 = {coords_array[2], coords_array[3]};
  point_t p3 = {coords_array[4], coords_array[5]};
  return new Parallelogram(p1, p2, p3);
}