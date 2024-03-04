#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "del_out_functions.hpp"
#include "isoscale.hpp"

//void inputShapes(std::istream & in, )

int main()
{
  using namespace lopatina;

  Shape * array[1000] = {};
  size_t counter = 0;
  int error_flag = 0;
  int figure_exist_flag = 0;

  while (counter != 1000)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "SCALE")
    {
      double center_x = 0.0, center_y = 0.0, index = 0.0;
      std::cin >> center_x >> center_y >> index;
      if (index <= 0.0)
      {
        std::cerr << "Incorrect scale index\n";
        deleteArray(array, counter);
        return 1;
      }

      if (figure_exist_flag == 0)
      {
        std::cerr << "Nothing to scale\n";
        return 1;
      }
      if (counter != 0)
      {
        outputResult(std::cout, array, counter);
        for (size_t i = 0; i < counter; ++i)
        {
          isoScale(array[i], {center_x, center_y}, index);
        }
        outputResult(std::cout, array, counter);
      }
      if (error_flag == 1)
      {
        std::cerr << "Some figure has wrong parameters\n";
      }
      deleteArray(array, counter);
      return 0;
    }
    if (!std::cin)
    {
      std::cerr << "No SCALE command entered\n";
      deleteArray(array, counter);
      return 1;
    }


   if (name == "RECTANGLE")
    {
      figure_exist_flag = 1;
      double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
      std::cin >> low_left_x >> low_left_y >> up_right_x >> up_right_y;
      try
      {
        array[counter++] = new Rectangle({low_left_x, low_left_y}, {up_right_x, up_right_y});
      }
      catch (const std::invalid_argument & e)
      {
        //std::cout << "rect: " << e.what() << '\n';
        error_flag = 1;
      }
    }

    if (name == "SQUARE")
    {
      figure_exist_flag = 1;
      double low_left_x = 0.0, low_left_y = 0.0, side = 0.0;
      std::cin >> low_left_x >> low_left_y >> side;
      try
      {
        array[counter++] = new Square({low_left_x, low_left_y}, side);
      }
      catch (const std::invalid_argument & e)
      {
        //std::cout << "sq: " << e.what() << '\n';
        error_flag = 1;
      }
    }

    if (name == "TRIANGLE")
    {
      figure_exist_flag = 1;
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      try
      {
        array[counter++] = new Triangle({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y});
      }
      catch (const std::invalid_argument & e)
      {
        //std::cout << "tri: " << e.what() << '\n';
        error_flag = 1;
      }
    }

    if (name == "DIAMOND")
    {
      figure_exist_flag = 1;
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      try
      {
        array[counter++] = new Diamond({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y});
      }
      catch (const std::invalid_argument & e)
      {
        //std::cout << "rect: " << e.what() << '\n';
        error_flag = 1;
      }
    }
  }
}
