#include "inputShapesSource.hpp"

#include <string>
#include <cctype>

#include "rectangle.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "inputString.hpp"

namespace zhalilov
{
  struct scale_t
  {
    point_t point;
    double ratio;
  };

  Shape *inputRectangle(std::istream &input)
  {
    double nums[4] = {};
    for (size_t i = 0; i < 4; i++)
    {
      input >> nums[i];
    }
    if (!input)
    {
      throw std::invalid_argument("incorrect rect src's num of args");
    }
    point_t leftCorner = { nums[0], nums[1] };
    point_t rightCorner = { nums[2], nums[3] };
    return new Rectangle(leftCorner, rightCorner);
  }

  Shape *inputCircle(std::istream &input)
  {
    double nums[3] = {};
    for (size_t i = 0; i < 3; i++)
    {
      input >> nums[i];
    }
    if (!input)
    {
      throw std::invalid_argument("incorrect circle src's num of args");
    }
    point_t center = { nums[0], nums[1] };
    double radius = nums[2];
    return new Circle(center, radius);
  }

  Shape *inputPolygon(std::istream &input)
  {
    size_t length = 0;
    size_t size = 10;
    double *nums = new double[size];
    while (input >> nums[length])
    {
      if (length + 1 == size)
      {
        double *newNums = nullptr;
        newNums = new double[size + 4]{};
        for (size_t j = 0; j < size; j++)
        {
          newNums[j] = nums[j];
        }
        delete[] nums;
        nums = newNums;
        size += 4;
      }
      length++;
    }
    if (length % 2 != 0 || length < 6)
    {
      throw std::invalid_argument("incorrect polygon src's nums of args");
    }
    point_t *points = new point_t[length / 2];
    for (size_t i = 0; i < length; i += 2)
    {
      points[i / 2] = { nums[i], nums[i + 1] };
    }
    try
    {
      Shape *shape = new Polygon(points, length / 2);
      delete[] points;
      return shape;
    }
    catch (const std::exception &e)
    {
      delete[] points;
      throw;
    }
  }

  Shape *identifyShape(const std::string &name, std::istream &input)
  {
    using shapeCreatingFunc = Shape *(*)(std::istream &input);
    size_t namesSize = 3;
    const std::string shapeNames[] = {"RECTANGLE", "CIRCLE", "POLYGON"};
    shapeCreatingFunc functions[3];
    functions[0] = inputRectangle;
    functions[1] = inputCircle;
    functions[2] = inputPolygon;
    for (size_t i = 0; i < namesSize; i++)
    {
      if (shapeNames[i] == name)
      {
        return functions[i](input);
      }
    }
    return nullptr;
  }
}

void zhalilov::inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input)
{
  size_t shapeIndex = 0;
  bool hasIncorrectShapes = false;
  while (true)
  {
    try
    {
      std::string name;
      input >> name;
      if (name == "SCALE")
      {
        input >> point.x >> point.y;
        input >> ratio;
        length = shapeIndex;
        if (ratio <= 0.0)
        {
          throw std::underflow_error("ratio scale should be greater than zero");
        }
        if (hasIncorrectShapes)
        {
          throw std::invalid_argument("some shapes have incorrect source");
        }
        return;
      }
      shapes[shapeIndex] = identifyShape(name, input);
      if (shapes[shapeIndex])
      {
        shapeIndex++;
      }
    }
    catch (const std::invalid_argument &e)
    {
      hasIncorrectShapes = true;
    }
    catch (const std::exception &e)
    {
      length = shapeIndex;
      throw;
    }
  }
}
