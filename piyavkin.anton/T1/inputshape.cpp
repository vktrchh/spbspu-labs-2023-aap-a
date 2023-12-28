#include <string>
#include "inputshape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

Shape ** inputShape(std::istream& in, size_t & shapeCount)
{
  std::string name = "";
  double* parameters = nullptr;
  std::string shapeNames[3] = { "RECTANGLE", "TRIANGLE", "PARALLELOGRAM" };
  size_t shapeParametersCount[3] = {4, 6, 6};
  Shape** shapeArray = nullptr;
  Shape** oldShapeArray = nullptr;
  char symbol = 0;
  while (in >> name)
  {
    for (size_t i = 0; i < 3; ++i)
    {
      if (name == shapeNames[i])
      {
        parameters = new double[shapeParametersCount[i]];
        for (size_t j = 0; j < shapeParametersCount[i]; ++j)
        {
          in >> parameters[j];
        }
        if (!in)
        {
          delete[] shapeArray;
          delete[] oldShapeArray;
          delete[] parameters;
          throw std::logic_error("Invalid arguments");
        }
        oldShapeArray = shapeArray;
        shapeArray = new Shape * [shapeCount + 1];
        if (oldShapeArray)
        {
          for (size_t i = 0; i < shapeCount + 1; ++i)
          {
            shapeArray[i] = oldShapeArray[i];
          }
        }
        delete[] oldShapeArray;
        if (name == "RECTANGLE")
        {
          shapeArray[shapeCount] = new Rectangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] });
        }
        else if (name == "TRIANGLE")
        {
          shapeArray[shapeCount] = new Triangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] });
        }
        else
        {
          shapeArray[shapeCount] = new Parallelogram({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] });
        }
        delete[] parameters;
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
  if (name == "")
  {
    throw std::logic_error("It is not shape");
  }
  return shapeArray;
}

