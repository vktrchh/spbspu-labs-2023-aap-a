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
#include "reader.hpp"

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
        belokurskaya::point_t * points = belokurskaya::readPointsArray(inputStream, 2);

        shapes[shape_count] = new belokurskaya::Rectangle(points[0], points[1]);
        shape_count++;
        delete[] points;
      }
      else if (command == "TRIANGLE")
      {
        belokurskaya::point_t * points = belokurskaya::readPointsArray(inputStream, 3);
        if (std::labs((points[1].x - points[0].x) * (points[2].y - points[0].y)
        - (points[2].x - points[0].x) * (points[1].y - points[0].y)) < 1e-9)
        {
          std::cerr << "Is not a triangle\n";
          continue;
        }
        shapes[shape_count] = new belokurskaya::Triangle(points[0], points[1], points[2]);
        shape_count++;
        delete[] points;
      }
      else if (command == "CONCAVE")
      {
        belokurskaya::point_t * points = belokurskaya::readPointsArray(inputStream, 4);

        shapes[shape_count] = new belokurskaya::Concave(points[0], points[1], points[2], points[3]);
        shape_count++;
        delete[] points;
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
