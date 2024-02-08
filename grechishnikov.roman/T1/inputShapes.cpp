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

grechishnikov::Shape* grechishnikov::inputShape(const char* str)
{
  const size_t legalNameCount = 3;
  const char* legalName[] = { "RECTANGLE\0", "TRIANGLE\0", "POLYGON\0" };

  const char* name = nullptr;
  const double* values = nullptr;
  size_t size = 0;
  const grechishnikov::point_t* points = nullptr;
  try
  {
    name = parseName(str);
    size_t pos = 0;
    for (size_t i = 0; str[i] != ' '; i++)
    {
      pos++;
    }
    values = grechishnikov::parseValues(str + pos, size);
    points = grechishnikov::makePairs(values, size);
    if (isEqualStr(legalName[0], name))
    {
      Shape* rect = grechishnikov::inputRectangle(points, size / 2);
      delete[] name;
      delete[] values;
      delete[] points;
      return rect;
    }
    if (isEqualStr(legalName[1], name))
    {
      Shape* tri = grechishnikov::inputTriangle(points, size / 2);
      delete[] name;
      delete[] values;
      delete[] points;
      return tri;
    }
    if (isEqualStr(legalName[2], name))
    {
      Shape* poly = grechishnikov::inputPolygon(points, size / 2);
      delete[] name;
      delete[] values;
      delete[] points;
      return poly;
    }
  }
  catch (const std::logic_error& e)
  {
    delete[] name;
    delete[] values;
    delete[] points;
    throw;
  }
  delete[] name;
  delete[] values;
  delete[] points;
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

void grechishnikov::freeShapes(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
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
