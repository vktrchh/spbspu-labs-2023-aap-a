#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include "results_printer.hpp"
#include "iso_scale.hpp"

int main()
{
  belokurskaya::Shape* shapes[1000];
  int shape_count = 0;

  try
  {
    while (true)
    {
      std::string input;
      if (!std::getline(std::cin, input))
      {
        if (std::cin.eof())
        {
          for (int i = 0; i < shape_count; ++i)
          {
            delete shapes[i];
          }
          std::cerr << "EOF reached\n";
          return 1;
        }
        continue;
      }
      if (input.empty())
      {
        continue;
      }
      std::istringstream inputStream(input);
      std::string command;
      inputStream >> command;

      if (command == "RECTANGLE")
      {
        double lower_left_x = 0.0;
        double lower_left_y = 0.0;
        double upper_right_x = 0.0;
        double upper_right_y = 0.0;
        if (!(inputStream >> lower_left_x >> lower_left_y >> upper_right_x >> upper_right_y))
        {
          continue;
        }

        belokurskaya::point_t lower_left = {lower_left_x, lower_left_y};
        belokurskaya::point_t upper_right = {upper_right_x, upper_right_y};

        shapes[shape_count] = new belokurskaya::Rectangle(lower_left, upper_right);
        shape_count++;
      }
      else if (command == "TRIANGLE")
      {
        double a_x = 0.0, a_y = 0.0, b_x = 0.0, b_y = 0.0, c_x = 0.0, c_y = 0.0;
        if (!(inputStream >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y))
        {
          continue;
        }

        if (std::labs((b_x - a_x) * (c_y - a_y) - (c_x - a_x) * (b_y - a_y)) < 1e-9)
        {
          std::cerr << "Is not a triangle\n";
          continue;
        }
        shapes[shape_count] = new belokurskaya::Triangle({a_x, a_y}, {b_x, b_y}, {c_x, c_y});
        shape_count++;
      }
      else if (command == "CONCAVE")
      {
        double a_x = 0.0;
        double a_y = 0.0;
        double b_x = 0.0;
        double b_y = 0.0;
        double c_x = 0.0;
        double c_y = 0.0;
        double d_x = 0.0;
        double d_y = 0.0;
        if (!(inputStream >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y >> d_x >> d_y))
        {
          continue;
        }

        shapes[shape_count] = new belokurskaya::Concave({a_x, a_y}, {b_x, b_y}, {c_x, c_y}, {d_x, d_y});
        shape_count++;
      }
      else if (command == "SCALE")
      {
        double scale_point_x = 0.0, scale_point_y = 0.0, scale_factor = 0.0;
        if (!(inputStream >> scale_point_x >> scale_point_y >> scale_factor))
        {
          throw std::invalid_argument("Invalid input for scale");
        }
        if (scale_factor <= 0.0)
        {
          for (int i = 0; i < shape_count; ++i)
          {
            delete shapes[i];
          }
          throw std::invalid_argument("Invalid scaling factor");
        }
        if (shape_count == 0)
        {
          return 1;
        }
        const belokurskaya::point_t scale_point = {scale_point_x, scale_point_y};
        belokurskaya::printResults(std::cout, shapes, shape_count);
        for (int i = 0; i < shape_count; ++i)
        {
          belokurskaya::isoScale(shapes[i], scale_point, scale_factor);
        }

        belokurskaya::printResults(std::cout, shapes, shape_count);
        break;
      }
      else
      {
        continue;
      }
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  for (int i = 0; i < shape_count; ++i)
  {
    delete shapes[i];
  }
  return 0;
}
