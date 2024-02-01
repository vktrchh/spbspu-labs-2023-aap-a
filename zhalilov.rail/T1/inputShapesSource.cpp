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
  struct scale_t
  {
    point_t point;
    double ratio;
  };

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
    using shapeCreatingFunc = Shape *(*)(const double nums[], size_t length);
    size_t namesSize = 3;
    const std::string shapeNames[] = {"RECTANGLE", "CIRCLE", "POLYGON"};
    shapeCreatingFunc functions[3];
    functions[0] = createRectangle;
    functions[1] = createCircle;
    functions[2] = createPolygon;
    for (size_t i = 0; i < namesSize; i++)
    {
      if (shapeNames[i] == name)
      {
        return functions[i](nums, length);
      }
    }
    return nullptr;
  }

  bool identifyScale(const std::string &name, const double nums[], size_t length, point_t &center, double &ratio)
  {
    if (name == "SCALE")
    {
      if (nums[2] <= 0.0)
      {
        throw std::underflow_error("ratio scale should be greater than zero");
      }
      center = { nums[0], nums[1] };
      ratio = nums[2];
      return true;
    }
    return false;
  }
}

void zhalilov::inputShapesSource(Shape **shapes, point_t &point, double &ratio, size_t &length, std::istream &input)
{
  size_t shapeIndex = 0;
  std::string srcName = "";
  size_t size = 10;
  bool hasIncorrectShapes = false;
  double *srcNums = new double[size];
  while (true)
  {
    try
    {
      input >> srcName;
      size_t numsLength = 0;
      while (input >> srcNums[numsLength])
      {
        if (numsLength + 1 == size)
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
        numsLength++;
      }

      shapes[shapeIndex] = identifyShape(srcName, srcNums, numsLength);
      if (shapes[shapeIndex])
      {
        shapeIndex++;
      }
      else if (identifyScale(srcName, srcNums, numsLength, point, ratio))
      {
        delete[] srcNums;
        length = shapeIndex;
        if (hasIncorrectShapes)
        {
          throw std::invalid_argument("some shapes have incorrect source");
        }
        return;
      }
    }
    catch (const std::invalid_argument &e)
    {
      hasIncorrectShapes = true;
    }
    catch (const std::exception &e)
    {
      delete[] srcNums;
      length = shapeIndex;
      throw;
    }
  }
}
