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
  size_t rectangleNameLen = 9;
  const char *newStr = string + rectangleNameLen;
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
  return new Rectangle(leftCorner, rightCorner);
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

bool zhalilov::isScaleInputed(const char string[])
{
  char name[] = "SCALE";
  size_t nameLen = 5;
  if ((strncmp(name, string, nameLen) == 0)
    && (isspace(string[nameLen])))
  {
    return true;
  }
  return false;
}

zhalilov::Shape **zhalilov::inputShapesSource(size_t &inputedShapes, size_t &processedShapes, double &ratio, std::istream &input)
{
  inputedShapes = 0;
  processedShapes = 0;
  char ratioLit[] = {"RATIO"};
  char *string = nullptr;
  Shape **shapes = nullptr;
  try
  {
    shapes = new Shape *[10];
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  while (true)
  {
    size_t lastDataIndex = 0;
    size_t size = 0;
    string = inputString(lastDataIndex, size, input);
    if (lastDataIndex == 0)
    {
      continue;
    }
    else if (string[lastDataIndex] != '\0')
    {
      inputedShapes++;
      continue;
    }

    if (isScaleInputed(string))
    {
      return shapes;
    }
    shapeInputFunc inputFunc = identifyShape(string);
    if (!inputFunc)
    {
      continue;
    }
    try
    {
      shapes[processedShapes] = inputFunc(string);
    }
    catch (const std::invalid_argument &e)
    {
      inputedShapes++;
      continue;
    }
    inputedShapes++;
    processedShapes++;
  }
}
