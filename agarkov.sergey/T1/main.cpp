#include <iostream>

#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "isoScale.hpp"

int main()
{
  std::string shape_name = "";
  double scale_coefficient = 0.0;
  agarkov::point_t scale_point{0.0, 0.0};
  size_t capacity = 10;
  size_t size = 0;
  agarkov::Shape** shapes = new agarkov::Shape*[capacity];
}
