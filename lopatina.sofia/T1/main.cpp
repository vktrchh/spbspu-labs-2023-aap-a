#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "side_functions.hpp"

//check_functions.cpp
using namespace lopatina;
bool isRectangleCorrect(point_t low_left, point_t up_right)
{
  if ((low_left.x_ == up_right.x_) || (low_left.y_ == up_right.y_))
  {
    return false;
  }
  if (((low_left.x_ > up_right.x_) && (low_left.y_ < up_right.y_)) || ((low_left.y_ > up_right.y_) && (low_left.x_ < up_right.x_)))
  {
    return false;
  }
  return true;
}
bool isTriangleCorrect(point_t p1, point_t p2, point_t p3)
{
  if (((p1.x_ == p2.x_) && (p1.y_ == p2.y_)) || ((p2.x_ == p3.x_) && (p2.y_ == p3.y_)) || ((p3.x_ == p1.x_) && (p3.y_ == p1.y_)))
  {
    return false;
  }
  if (((p1.x_ == p2.x_) && (p2.x_  == p3.x_)) || ((p1.y_ == p2.y_) && (p2.y_ == p3.y_)))
  {
    return false;
  }
  return true;
}


//-----


int main()
{
  using namespace lopatina;

  Shape * array[1000] = {};
  size_t counter = 0;
  int error_flag = 0;

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

      if (counter != 0)
      {
        outputResult(std::cout, array, counter);
        for (size_t i = 0; i < counter; ++i)
        {
          array[i]->scale({center_x, center_y}, index);
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
      double low_left_x = 0.0, low_left_y = 0.0, up_right_x = 0.0, up_right_y = 0.0;
      std::cin >> low_left_x >> low_left_y >> up_right_x >> up_right_y;
      if (!isRectangleCorrect({low_left_x, low_left_y}, {up_right_x, up_right_y}))
      {
        error_flag = 1;
      }
      else
      {
        if (low_left_x > up_right_x)
        {
          double x1 = low_left_x, x2 = up_right_x;
          low_left_x = x2;
          up_right_x = x1;
        }
        if (low_left_y > up_right_y)
        {
          double y1 = low_left_y, y2 = up_right_y;
          low_left_y = y2;
          up_right_y = y1;
        }
        array[counter++] = new Rectangle({low_left_x, low_left_y}, {up_right_x, up_right_y});
      }
    }

    if (name == "SQUARE")
    {
      double low_left_x = 0.0, low_left_y = 0.0, side = 0.0;
      std::cin >> low_left_x >> low_left_y >> side;
      if (side <= 0.0)
      {
        error_flag = 1;
      }
      else
      {
        array[counter++] = new Square({low_left_x, low_left_y}, side);
      }
    }

    if (name == "TRIANGLE")
    {
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      if (!isTriangleCorrect({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y}))
      {
        error_flag = 1;
      }
      else
      {
        array[counter++] = new Triangle({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y});
      }
    }

    if (name == "DIAMOND")
    {
      double point1_x = 0.0, point1_y = 0.0, point2_x = 0.0, point2_y = 0.0, point3_x = 0.0, point3_y = 0.0;
      std::cin >> point1_x >> point1_y >> point2_x >> point2_y >> point3_x >> point3_y;
      if (!isTriangleCorrect({point1_x, point1_y}, {point2_x, point2_y}, {point3_x, point3_y}))
      {
        error_flag = 1;
      }
      else
      {
        point_t point1 = {0.0, 0.0};
        point_t point2 = {0.0, 0.0};
        point_t point3 = {0.0, 0.0};
        point_t central_point = {0.0, 0.0};
        point_t side_point_x = {0.0, 0.0};
        point_t side_point_y = {0.0, 0.0};
        int flag = 0;

        for (size_t i = 1; i < 4; ++i)
        {
          if (i == 1)
          {
            point1 = {point1_x, point1_y};
            point2 = {point2_x, point2_y};
            point3 = {point3_x, point3_y};
          }
          if (i == 2)
          {
            point1 = {point2_x, point2_y};
            point2 = {point1_x, point1_y};
            point3 = {point3_x, point3_y};
          }
          if (i == 3)
          {
            point1 = {point3_x, point3_y};
            point2 = {point1_x, point1_y};
            point3 = {point2_x, point2_y};
          }
          if (isCentralPoint(point1, point2, point3))
          {
            flag = 1;
            central_point = {point1.x_, point1.y_};
            side_point_x = defineSidePointX(point1, point2, point3);
            side_point_y = defineSidePointY(point1, point2, point3);
          }
        }
        if (flag == 0)
        {
          error_flag = 1;
        }
        else
        {
          array[counter++] = new Diamond(central_point, side_point_x, side_point_y);
        }
      }
    }
  }
}
