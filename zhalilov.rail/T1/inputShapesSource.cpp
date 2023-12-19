#include "inputShapesSource.hpp"

#include <cstring>
#include <string>
#include <cctype>

#include "Rectangle.hpp"
#include "inputString.hpp"

zhalilov::Shape *zhalilov::inputRectangle(const char string[])
{
  double coords[4] = {};
  size_t delta = 0;
  size_t nameLen = 9;
  const char *newStr = string + nameLen;
  for (size_t i = 0; i < 4; i++)
  {
    coords[i] = std::stod(newStr, &delta);
    newStr = newStr + delta;
  }
  if (*newStr != '\0')
  {
    throw std::invalid_argument("Too many args in rect source");
  }
  point_t leftCorner = {coords[0], coords[1]};
  point_t rightCorner = {coords[2], coords[3]};
  Shape * rect = new Rectangle(leftCorner, rightCorner);
  return rect;
}

shapeInputFunc zhalilov::identifyShape(const char string[])
{
  char *names[] = {"RECTANGLE"};
  shapeInputFunc functions[1];
  functions[0] = inputRectangle;
  size_t namesSize = 1;
  for (size_t i = 0; i < namesSize; i++)
  {
    size_t nameLen = strlen(names[i]);
    if ((strncmp(names[i], string, nameLen) == 0)
      && (isspace(string[nameLen])))
    {
      return functions[i];
    }
  }
  return nullptr;
}

bool zhalilov::inputScale(ShapeSource *shapeSource, const char string[])
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
    double ratio = std::stod(newStr, &delta);

    if (*(newStr + delta) != '\0')
    {
      throw std::invalid_argument("Invalid scaling source");
    }
    if (ratio <= 0.0)
    {
      throw std::invalid_argument("Scaling ration should be greater than zero");
    }

    shapeSource->scalePoint = {x, y};
    shapeSource->scaleRatio = ratio;
    return true;
  }
  return false;
}

zhalilov::ShapeSource *zhalilov::inputShapesSource(ShapeSource *shapeSource, std::istream &input)
{
  size_t shapeIndex = 0;
  char *string = nullptr;
  while (true)
  {
    try
    {
      string = inputString(input);
    }
    catch (const std::bad_alloc &e)
    {
      shapeSource->wasBadShapes = true;
      continue;
    }

    try
    {
      if (inputScale(shapeSource, string))
      {
        delete[] string;
        return shapeSource;
      }
    }
    catch (const std::invalid_argument &e)
    {
      delete[] string;
      throw;
    }
    shapeInputFunc inputFunc = identifyShape(string);
    if (!inputFunc)
    {
      delete[] string;
      continue;
    }
    try
    {
      shapeSource->add(inputFunc(string));
    }
    catch (const std::invalid_argument &e)
    {
      shapeSource->wasBadShapes = true;
      delete[] string;
      continue;
    }
    delete[] string;
    shapeIndex++;
  }
}
