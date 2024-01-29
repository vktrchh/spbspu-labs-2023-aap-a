#include "inputShapesSource.hpp"

#include <cstring>
#include <string>
#include <cctype>

#include "rectangle.hpp"
#include "circle.hpp"
#include "polygon.hpp"
#include "inputString.hpp"

namespace zhalilov
{
  Shape *createRectangle(const double nums[], size_t length)
  {
    if (length != 4)
    {
      throw std::invalid_argument("incorrect rect src's num of args");
    }
    point_t leftCorner = { nums[0], nums[1] };
    point_t rightCorner = { nums[2], nums[3] };
    return new Rectangle(leftCorner, rightCorner);
  }

  Shape *createCircle(const double nums[], size_t length)
  {
    if (length != 3)
    {
      throw std::invalid_argument("incorrect circle src's num of args");
    }
    point_t center = { nums[0], nums[1] };
    double radius = nums[2];
    return new Circle(center, radius);
  }

  Shape *createPolygon(const double nums[], size_t length)
  {
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

  Shape *identifyShape(const std::string &name, const double nums[], size_t length)
  {
    std::string names[] = {"RECTANGLE", "CIRCLE", "POLYGON"};
    using shapeCreatingFunc = Shape *(*)(const double nums[], size_t length);
    shapeCreatingFunc functions[3];
    functions[0] = inputRectangle;
    functions[1] = inputCircle;
    functions[2] = inputPolygon;
    size_t namesSize = 3;
    for (size_t i = 0; i < namesSize; i++)
    {
      if (names[i] == name)
      {
        return functions[i](nums, length);
      }
    }
    return nullptr;
  }

  bool inputScale(point_t &point, double &ratio, const char string[])
  {
    char name[] = "SCALE";
    size_t nameLen = 5;
    if ((strncmp(name, string, nameLen) == 0)
      && (isspace(string[nameLen])))
    {
      const char *newStr = string + nameLen;
      size_t delta = 0;
      double x = std::stod(newStr, &delta);
      newStr += delta;
      double y = std::stod(newStr, &delta);
      newStr += delta;
      double inputedRatio = std::stod(newStr, &delta);

      point = { x, y };
      ratio = inputedRatio;
      return true;
    }
    return false;
  }
}

void zhalilov::freeShapesMemory(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
    shapes[i] = nullptr;
  }
}

zhalilov::Shape **zhalilov::inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input)
{
  size_t shapeIndex = 0;
  std::string srcName = "";
  size_t size = 10;
  bool hasIncorrectShapes = false;
  double srcNums = new double[size];
  while (true)
  {
    try
    {
      input >> srcName;
      size_t i = 0;
      while (input >> srcNums[i])
      {
        if (i + 1 == size)
        {
          double *newNums = nullptr;
          newNums = new double[size + 4]{};
          for (size_t j = 0; j < size; j++)
          {
            newNums[j] = srcNums[j];
          }
          delete[] srcNums;
          srcNums = newNums;
          size += 4;
        }
        i++;
      }

      shapes[shapeIndex] = identifyShape(string);
      if (shapes[shapeIndex])
      {
        shapeIndex++;
      }
    }
    catch (const std::invalid_argument &e)
    {
      hasIncorrectShapes = true;
    }
    catch (const std::bad_alloc &e)
    {
      delete[] srcNums;
      length = shapeIndex;
      throw;
    }

    if (inputScale(point, ratio, string))
    {
      delete[] string;
      length = shapeIndex;
      return shapes;
    }
    delete[] string;
    string = nullptr;
  }
  delete[] srcNums;
}
