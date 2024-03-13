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
  //double scale_coefficient = 0.0;
  //agarkov::point_t scale_point{0.0, 0.0};
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
      if (shape_name == "RECTANGLE")
      {
        double parameters[4]{};
        std::cin >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
        shape = new agarkov::Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
        shapes[size] = shape;
        std::cout << shapes[size]->getArea() << "\n";
        size++;
      }
      if (shape_name == "SQUARE")
      {
        double parameters[3]{};
        std::cin >> parameters[0] >> parameters[1] >> parameters[2];
        shape = new agarkov::Square({parameters[0], parameters[1]}, parameters[2]);
        shapes[size] = shape;
        std::cout << shapes[size]->getArea() << "\n";
        size++;
      }
    }
    catch (...)
    {
      std::cerr << "Error\n";
      agarkov::deleteArray(shapes, size);
      return 1;
    }
  }
  while (std::cin);
}
