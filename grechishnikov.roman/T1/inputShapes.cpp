#include "inputShapes.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "parametersLogic.hpp"
#include <stdexcept>
#include <cctype>

grechishnikov::Shape* grechishnikov::inputRectangle(const grechishnikov::point_t* points, size_t size);
grechishnikov::Shape* grechishnikov::inputTriangle(const grechishnikov::point_t* points, size_t size);
grechishnikov::Shape* grechishnikov::inputPolygon(const grechishnikov::point_t* points, size_t size);
const char* parseName(const char* str);
bool isEqualStr(const char* fStr, const char* sStr);

grechishnikov::Shape* grechishnikov::inputShapes(const char* str)
{
  const size_t legalNameCount = 3;
  const char* legalName[] = { "RECTANGLE", "TRIANGLE", "POLYGON" };

  const char* name = nullptr;
  const double* values = nullptr;
  size_t size = 0;
  const grechishnikov::point_t* points = nullptr;
  try
  {
    name = parseName(str);
    size_t pos = 0;
    for (size_t i = 0; str[i] != 0; i++)
    {
      pos++;
    }
    values = grechishnikov::parseValues(str + pos, size);
    points = grechishnikov::makePairs(values, size);
    if (isEqualStr(legalName[0], name))
    {
      return grechishnikov::inputRectangle(points, size / 2);
    }
    if (isEqualStr(legalName[1], name))
    {
      return grechishnikov::inputTriangle(points, size / 2);
    }
    if (isEqualStr(legalName[2], name))
    {
      return grechishnikov::inputPolygon(points, size / 2);
    }
  }
  catch (const std::logic_error& e)
  {
    delete[] name;
    delete[] values;
    delete[] points;
    throw;
  }
  throw std::logic_error("Incorrect name");
}

grechishnikov::Shape* grechishnikov::inputRectangle(const grechishnikov::point_t* points, size_t size)
{
  if (size != 2)
  {
    throw std::logic_error("Incorrect number of parameters");
  }
  return new grechishnikov::Rectangle(points[0], points[1]);
}

grechishnikov::Shape* grechishnikov::inputTriangle(const grechishnikov::point_t* points, size_t size)
{
  if (size != 3)
  {
    throw std::logic_error("Incorrect number of parameters");
  }
  return new grechishnikov::Triangle(points[0], points[1], points[2]);
}

grechishnikov::Shape* grechishnikov::inputPolygon(const grechishnikov::point_t* points, size_t size)
{
  if (size < 3)
  {
    throw std::logic_error("Incorrect number of parameters");
  }
  return new grechishnikov::Polygon(points, size);
}

const char* parseName(const char* str)
{
  char* name = new char [20] { '0' };
  for (size_t i = 0; str[i] != ' '; i++)
  {
    if (std::isalpha(str[i]))
    {
      name[i] = str[i];
      name[i + 1] = '\0';
    }
    else
    {
      delete[] name;
      throw std::logic_error("Incorrect name input");
    }
  }
  return name;
}

bool isEqualStr(const char* fStr, const char* sStr)
{
  bool check = 1;
  size_t i = 0;
  for (i = 0; fStr[i] != '\0' || sStr[i] != '\0'; i++)
  {
    if (fStr[i] != sStr[i])
    {
      check = 0;
    }
  }
  if (fStr[i + 1] != sStr[i + 1])
  {
    check = 0;
  }
  return check;
}
