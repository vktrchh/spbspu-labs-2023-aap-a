#include <iostream>
#include <string>

#include "shape.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "isoScale.hpp"
#include "printShapes.hpp"
#include "workWithArray.hpp"

int main()
{
  std::string shape_name = "";
  double scale_coefficient = 0.0;
  agarkov::point_t scale_point{0.0, 0.0};
  size_t capacity = 10;
  size_t buf = 10;
  size_t size = 0;
  agarkov::Shape** shapes = new agarkov::Shape*[capacity];
  do
  {
    agarkov::Shape* shape = nullptr;
    try
    {
      if (size + 1 == capacity)
      {
        agarkov::Shape** expanded_shapes = agarkov::expandArray(shapes, capacity, buf);
        capacity += buf;
        delete[] shapes;
        shapes = expanded_shapes;
      }
      std::cin >> shape_name;
    catch (...)
    {
      std::cerr << "Error\n";
      hrushchev::deleteArray(shapes, size);
      return 1;
    }
  }
  while (std::cin);
}
