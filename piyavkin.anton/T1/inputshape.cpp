#include "inputshape.hpp"
#include <string>
#include <iostream>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

void piyavkin::clearMemory(Shape** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

void piyavkin::inputRectangle(std::istream& in, Shape** shapes, size_t shapeCount)
{
  const size_t parametersCount = 4;
  double parameters[parametersCount] = {};
  for (size_t j = 0; j < parametersCount; ++j)
  {
    in >> parameters[j];
  }
  if (!in)
  {
    throw std::logic_error("Invalid arguments");
  }
  shapes[shapeCount] = new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
}

void piyavkin::inputTriangle(std::istream& in, Shape** shapes, size_t shapeCount)
{
  const size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  for (size_t j = 0; j < parametersCount; ++j)
  {
    in >> parameters[j];
  }
  if (!in)
  {
    throw std::logic_error("Invalid arguments");
  }
  shapes[shapeCount] = new Triangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
}

void piyavkin::inputParallelogram(std::istream& in, Shape** shapes, size_t shapeCount)
{
  const size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  for (size_t j = 0; j < parametersCount; ++j)
  {
    in >> parameters[j];
  }
  if (!in)
  {
    throw std::logic_error("Invalid arguments");
  }
  shapes[shapeCount] = new Parallelogram({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
}

piyavkin::Shape** piyavkin::inputShape(std::istream& in, size_t& shapeCount)
{
  std::string name = "";
  const size_t numbersFigures = 3;
  std::string shapeNames[numbersFigures] = {"RECTANGLE", "TRIANGLE", "PARALLELOGRAM"};
  Shape** shapeArray = nullptr;
  Shape** oldShapeArray = nullptr;
  char symbol = 0;
  while (in >> name)
  {
    for (size_t i = 0; i < numbersFigures; ++i)
    {
      if (name == shapeNames[i])
      {
        oldShapeArray = shapeArray;
        shapeArray = new Shape* [shapeCount + 1] {};
        if (oldShapeArray)
        {
          for (size_t i = 0; i < shapeCount; ++i)
          {
            shapeArray[i] = oldShapeArray[i];
          }
        }
        delete[] oldShapeArray;
        try
        {
          if (name == "RECTANGLE")
          {
            inputRectangle(in, shapeArray, shapeCount);
          }
          else if (name == "TRIANGLE")
          {
            inputTriangle(in, shapeArray, shapeCount);
          }
          else if (name == "PARALLELOGRAM")
          {
            inputParallelogram(in, shapeArray, shapeCount);
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << '\n';
          continue;
        }
        catch (const std::bad_alloc& e)
        {
          clearMemory(shapeArray, shapeCount);
          throw;
        }
        ++shapeCount;
      }
    }
    if (name == "SCALE")
    {
      break;
    }
    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }
  if (!in)
  {
    clearMemory(shapeArray, shapeCount);
    throw std::logic_error("It is not shape");
  }
  return shapeArray;
}

