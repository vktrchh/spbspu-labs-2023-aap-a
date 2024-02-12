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
  double total_area_before_scaling = 0.0;
  double total_area_after_scaling = 0.0;

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
          std::cerr << "Is a rectangle\n";
          continue;
        }
        double width = std::abs(upper_right_x - lower_left_x);
        double height = std::abs(upper_right_y - lower_left_y);
        double center_x = (lower_left_x + upper_right_x) / 2.0;
        double center_y = (lower_left_y + upper_right_y) / 2.0;
        shapes[shape_count] = new belokurskaya::Rectangle({ center_x, center_y }, width, height);
        total_area_before_scaling += shapes[shape_count]->getArea();
        shape_count++;
      }
      else if (command == "TRIANGLE" && shape_count < max_shapes)
      {
        double vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y;
        inputStream >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y;

        if (std::labs((vertex2_x - vertex1_x) * (vertex3_y - vertex1_y) - (vertex3_x - vertex1_x) * (vertex2_y - vertex1_y)) > 1e-9)
        {
          shapes[shape_count] = new belokurskaya::Triangle({vertex1_x, vertex1_y}, {vertex2_x, vertex2_y}, {vertex3_x, vertex3_y});
          total_area_before_scaling += shapes[shape_count]->getArea();
          shape_count++;
        }
        else
        {
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
          total_area_before_scaling += shapes[shape_count]->getArea();
          shape_count++;
        }
        else
        {
          std::cerr << "Is not a concave\n";
        }
      }
      else if (command == "SCALE")
      {
        double scale_point_x, scale_point_y, scale_factor;
        inputStream >> scale_point_x >> scale_point_y >> scale_factor;
        if (scale_factor <= 0.0)
        {
          delete shapes[shape_count];
          throw std::invalid_argument("Invalid scaling factor");
        }
        if (shape_count == 0)
        {
          return 1;
        }
        for (int i = 0; i < shape_count; ++i)
        {
          try
          {
            belokurskaya::isoScale(shapes[i], shapes[i]->getFrameRect().pos, scale_factor);
            total_area_after_scaling += shapes[i]->getArea();
          }
          catch (const std::invalid_argument& e)
          {
            std::cerr << "Error: " << e.what() << "\n";
          }
        }
        printResults(shapes, shape_count, total_area_before_scaling, total_area_after_scaling);
        break;
      }
      else
      {
        std::cerr << "Unknown command.\n";
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
