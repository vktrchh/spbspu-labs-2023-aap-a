#include "inputShapesSource.hpp"

#include <cstring>
#include <cctype>

#include "Rectangle.hpp"
#include "inputString.hpp"

zhalilov::Shape *zhalilov::inputRectangle(char string[])
{
  return new Rectangle;
}

shapeInputFunc zhalilov::identifyShape(char string[])
{
  char *names[] = {"RECTANGLE"};
  shapeInputFunc functions[1];
  functions[0] = inputRectangle;
  size_t namesLen = 1;
  for (size_t i = 0; i < namesLen; i++)
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

zhalilov::Shape *zhalilov::inputShapesSource(size_t &inputedShapes, size_t &processedShapes, double &ratio, std::istream &input)
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
