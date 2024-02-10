#include <stdexcept>
#include <iostream>
#include "inputString.hpp"
#include "inputShapes.hpp"
#include "parametersLogic.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "isoScale.hpp"

int main()
{
  using namespace grechishnikov;

  const char* str = nullptr;
  const char* name = nullptr;
  Shape* shapes[1000] = { nullptr };

  const size_t legalNameCount = 3;
  const char* legalName[] = { "RECTANGLE\0", "TRIANGLE\0", "POLYGON\0" };

  size_t count = 0;
  bool endOfInput = false;
  try
  {
    while (!endOfInput)
    {
      const char* tempStr = inputString(std::cin);
      delete[] str;
      str = tempStr;
      const char* tempName = parseName(str);
      delete[] name;
      name = tempName;

      for (size_t i = 0; i < legalNameCount; i++)
      {
        if (isEqualStr(legalName[i], name))
        {
          shapes[count] = inputShape(str);
          count++;
        }
      }

      if (isEqualStr(name, "SCALE\0"))
      {
        endOfInput = true;

        if (count == 0)
        {
          throw std::logic_error("Nothing to scale");
        }
        size_t size = 0;
        const double* values = parseValues(str + 5, size);
        if (size != 3)
        {
          delete[] values;
          throw std::logic_error("Incorrect number of parameters to scale");
        }



        for (size_t g = 0; g < count; g++)
        {
          isoScale(shapes[g], { values[0], values[1] }, values[2]);
        }



        delete[] values;
        delete[] str;
        delete[] name;
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << "Cannot allocate enough memory" << '\n';
    return 2;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cout << e.what() << '\n';
    return 1;
  }

  for (size_t i = 0; i < count; i++)
  {
    std::cout << shapes[i]->getArea() << '\n';
  }

  freeShapes(shapes, count);
}
