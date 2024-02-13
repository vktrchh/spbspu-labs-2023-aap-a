#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include "iso_scale.hpp"
#include "results_printer.hpp"

int main()
{
  const int max_shapes = 1000;
  belokurskaya::Shape* shapes[max_shapes];
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
        double lower_left_x, lower_left_y, upper_right_x, upper_right_y;
        if (!(inputStream >> lower_left_x >> lower_left_y >> upper_right_x >> upper_right_y))
        {
          continue;
        }

        if (lower_left_x >= upper_right_x || lower_left_y >= upper_right_y)
        {
          std::cerr << "Is not a rectangle\n";
          continue;
        }
        belokurskaya::point_t lower_left = {lower_left_x, lower_left_y};
        belokurskaya::point_t upper_right = {upper_right_x, upper_right_y};

        shapes[shape_count] = new belokurskaya::Rectangle(lower_left, upper_right);
        shape_count++;
      }
      else if (command == "TRIANGLE")
      {
        double vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y;
        if (!(inputStream >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y))
        {
          continue;
        }

        double a = sqrt(pow(vertex2_x - vertex1_x, 2) + pow(vertex2_y - vertex1_y, 2));
        double b = sqrt(pow(vertex3_x - vertex2_x, 2) + pow(vertex3_y - vertex2_y, 2));
        double c = sqrt(pow(vertex1_x - vertex3_x, 2) + pow(vertex1_y - vertex3_y, 2));
        if (a + b <= c || a + c <= b || b + c <= a)
        {
          std::cerr << "Is not a triangle\n";
          continue;
        }

        if (std::labs((vertex2_x - vertex1_x) * (vertex3_y - vertex1_y) - (vertex3_x - vertex1_x) * (vertex2_y - vertex1_y)) < 1e-9)
        {
          std::cerr << "Is not a triangle\n";
          continue;
        }
        shapes[shape_count] = new belokurskaya::Triangle({vertex1_x, vertex1_y}, {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y});
        shape_count++;
      }
      else if (command == "CONCAVE")
      {
        double vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y, vertex4_x, vertex4_y;
        if (!(inputStream >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y >> vertex4_x >> vertex4_y))
        {
          continue;
        }
        if (!belokurskaya::Concave::isConcave({vertex1_x, vertex1_y},
        {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y}, {vertex4_x, vertex4_y}))
        {
          std::cerr << "Is not a concave\n";
          continue;
        }
        try
        {
          shapes[shape_count] = new belokurskaya::Concave({vertex1_x, vertex1_y},
          {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y}, {vertex4_x, vertex4_y});
          shape_count++;
        }
        catch(const std::invalid_argument& e)
        {
          std::cerr << e.what() << "\n";
        }
      }
      else if (command == "SCALE")
      {
        double scale_point_x, scale_point_y, scale_factor;
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
        belokurskaya::printResults(shapes, shape_count);
        for (int i = 0; i < shape_count; ++i)
        {
          try
          {
            belokurskaya::isoScale(shapes[i], scale_point, scale_factor);
          }
          catch (const std::invalid_argument& e)
          {
            std::cerr << "Error: " << e.what() << "\n";
          }
        }
        belokurskaya::printResults(shapes, shape_count);
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
