#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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
    std::string input;
    while (std::getline(std::cin, input))
    {
      if (input.empty())
      {
        continue;
      }
      std::istringstream inputStream(input);
      std::string command;
      inputStream >> command;

      if (command == "RECTANGLE" && shape_count < max_shapes)
      {
        double lower_left_x, lower_left_y, upper_right_x, upper_right_y;
        if (!(inputStream >> lower_left_x >> lower_left_y >> upper_right_x >> upper_right_y))
        {
          std::cerr << "Invalid input for rectangle\n";
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
      else if (command == "TRIANGLE" && shape_count < max_shapes)
      {
        double vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y;
        inputStream >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y;

        if (std::labs((vertex2_x - vertex1_x) * (vertex3_y - vertex1_y) - (vertex3_x - vertex1_x) * (vertex2_y - vertex1_y)) > 1e-9)
        {
          shapes[shape_count] = new belokurskaya::Triangle({vertex1_x, vertex1_y}, {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y});
          shape_count++;
        }
        else
        {
          std::cerr << "Is not a triangle\n";
          continue;
        }
      }
      else if (command == "CONCAVE" && shape_count < max_shapes)
      {
        double vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y, vertex4_x, vertex4_y;
        inputStream >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y >> vertex4_x >> vertex4_y;
        if (belokurskaya::Concave::isConcave({vertex1_x, vertex1_y}, {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y}, {vertex4_x, vertex4_y}))
        {
          shapes[shape_count] = new belokurskaya::Concave({vertex1_x, vertex1_y},
          {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y}, {vertex4_x, vertex4_y});
          shape_count++;
        }
        else
        {
          std::cerr << "Is not a concave\n";
          continue;
        }
      }
      else if (command == "SCALE")
      {
        double scale_point_x, scale_point_y, scale_factor;
        inputStream >> scale_point_x >> scale_point_y >> scale_factor;
        belokurskaya::point_t scale_point = {scale_point_x, scale_point_y};
        if (scale_factor <= 0.0)
        {
          for (int i = 0; i < shape_count; ++i)
          {
            delete shapes[i];
            shapes[i] = nullptr;
          }
          delete[] shapes;
          throw std::invalid_argument("Invalid scaling factor");
        }
        if (shape_count == 0)
        {
          return 1;
        }
        printResults(shapes, shape_count);
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
        printResults(shapes, shape_count);
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
    shapes[i] = nullptr;
  }
  return 0;
}
