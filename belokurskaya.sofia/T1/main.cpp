#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

#include "rectangle.hpp"

int main()
{
  const int max_shapes = 1000;
  Shape* shapes[max_shapes];
  int shape_count = 0;

  std::string input;
  while (std::getline(std::cin, input))
  {
    std::istringstream inputStream(input);
    std::string command;
    inputStream >> command;

    if (command == "RECTANGLE" && shape_count < max_shapes)
    {
      double lower_left_x, lower_left_y, upper_right_x, upper_right_y;
      inputStream >> lower_left_x >> lower_left_y >> upper_right_x >> upper_right_y;
      double width = std::abs(upper_right_x - lower_left_x);
      double height = std::abs(upper_right_y - lower_left_y);
      double center_x = (lower_left_x + upper_right_x) / 2.0;
      double center_y = (lower_left_y + upper_right_y) / 2.0;
      shapes[shape_count++] = new Rectangle({ center_x, center_y }, width, height);
      std::cout << width * height << " " << lower_left_x << " " << lower_left_y << " " << upper_right_x << " " << upper_right_y << "\n";
    }
    else if (command == "SCALE")
    {
      double scale_point_x, scale_point_y, scale_factor;
      inputStream >> scale_point_x >> scale_point_y >> scale_factor;
      for (int i = 0; i < shape_count; ++i)
      {
        try
        {
          double dx = (shapes[i]->getFrameRect().pos.x - scale_point_x) * scale_factor;
          double dy = (shapes[i]->getFrameRect().pos.y - scale_point_y) * scale_factor;
          shapes[i]->move({ scale_point_x, scale_point_y});
          shapes[i]->scale(scale_factor);
          shapes[i]->move({ -dx, -dy });
        }
        catch (const std::invalid_argument& e)
        {
          std::cerr << "Error: " << e.what() << "\n";
        }
      }
      break;
    }
    else
    {
      std::cerr << "Unknown command.\n";
      return 1;
    }
  }

  for (int i = 0; i < shape_count; ++i)
  {
    std::cout << shapes[i]->getArea() << " ";
    rectangle_t frameRect = shapes[i]->getFrameRect();
    double scale_lower_left_x = frameRect.pos.x - frameRect.width / 2.0;
    double scale_lower_left_y = frameRect.pos.y - frameRect.height / 2.0;
    double scale_upper_right_x = frameRect.pos.x + frameRect.width / 2.0;
    double scale_upper_right_y = frameRect.pos.y + frameRect.height / 2.0;
    std::cout << scale_lower_left_x << " " << scale_lower_left_y << " " << scale_upper_right_x << " " << scale_upper_right_y << "\n";

    delete shapes[i];
  }
  return 0;
}
