#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include <cstring>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "Parallelogram.hpp"
#include "inputShapes.hpp"
#include "stringProc.hpp"

using namespace strelyaev;
int main ()
{
  bool marker = true;
  size_t current_index = 0;
  Shape ** list = new Shape * [1000]{};
  const char ** errors = new const char * [1000]{};
  size_t errors_count = 0;

  std::cin >> std::noskipws;
  while (marker)
  {

    char * string = nullptr;
    try
    {
      string = inputString(std::cin);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      break;
    }
    if (strncmp("SCALE", string, 5) == 0)
    {
      if (current_index == 0)
      {
        std::cerr << "Nothing to scale\n";
        delete [] string;
        break;
      }
      double arguments[3]{};
      size_t pos = 0;
      const char * argument_string = string + 6;
      for (size_t i = 0; i < 3; ++i)
      {
        arguments[i] = std::stod(argument_string, std::addressof(pos));
        argument_string += pos;
      }
      const point_t center = {arguments[0], arguments[1]};
      for (size_t i = 0; i < 1000; i++)
      {
        if (list[i] == 0)
        {
          break;
        }
        rectangle_t rect = list[i]->getFrameRect();
        double left_bottom_x = rect.pos_.x_ - rect.width_ / 2;
        double left_bottom_y = rect.pos_.y_ - rect.height_ / 2;
        double right_top_x = rect.pos_.x_ + rect.width_ / 2;
        double right_top_y = rect.pos_.y_ + rect.height_ / 2;
        std::cout << list[i]->getArea() << " " << left_bottom_x << " ";
        std::cout << left_bottom_y << " " << right_top_x << " " << right_top_y << "\n";

        isotrScale(list[i], center, arguments[2]);

        rect = list[i]->getFrameRect();
        left_bottom_x = rect.pos_.x_ - rect.width_ / 2;
        left_bottom_y = rect.pos_.y_ - rect.height_ / 2;
        right_top_x = rect.pos_.x_ + rect.width_ / 2;
        right_top_y = rect.pos_.y_ + rect.height_ / 2;
        std::cout << list[i]->getArea() << " " << left_bottom_x << " ";
        std::cout << left_bottom_y << " " << right_top_x << " " << right_top_y << "\n";
        delete list[i];

      }
      delete [] string;
      break;
    }

    Shape * new_shape = nullptr;
    try
    {
      new_shape = getShape(string);
      if (new_shape != nullptr)
      {
        list[current_index++] = new_shape;
      }
    }
    catch(const std::invalid_argument & e)
    {
      errors[errors_count++] = e.what();
      delete [] string;
      continue;
    }
    delete [] string;
  }
  std::cin >> std::skipws;

  for (size_t i = 0; i < 1000; i++)
  {
    if (errors[i] == 0)
    {
      break;
    }
    std::cerr << errors[i] << "\n";
  }
  delete [] list;
  delete [] errors;
}
